
#include <libsystem/assert.h>
#include <libsystem/eventloop/EventLoop.h>
#include <libsystem/eventloop/Notifier.h>
#include <libsystem/eventloop/Timer.h>
#include <libsystem/logger.h>
#include <libsystem/utils/List.h>

typedef struct
{
    RunLaterCallback callback;
    void *target;
} RunLater;

static List *_eventloop_timers = NULL;
static TimeStamp _eventloop_timer_last_fire = 0;

static List *_eventloop_notifiers = NULL;
static List *_eventloop_run_later = NULL;

static size_t _eventloop_handles_count;
static Handle *_eventloop_handles[PROCESS_HANDLE_COUNT];
static SelectEvent _eventloop_events[PROCESS_HANDLE_COUNT];

static bool _eventloop_is_running = false;
static bool _eventloop_is_initialize = false;
static int _eventloop_exit_value = 0;

void eventloop_initialize(void)
{
    assert(!_eventloop_is_initialize);

    _eventloop_timers = list_create();
    _eventloop_timer_last_fire = system_get_ticks();

    _eventloop_notifiers = list_create();
    _eventloop_run_later = list_create();

    _eventloop_is_initialize = true;
}

void eventloop_uninitialize(void)
{
    assert(_eventloop_is_initialize);
    assert(!_eventloop_is_running);

    list_destroy(_eventloop_notifiers);
    list_destroy(_eventloop_timers);
    list_destroy_with_callback(_eventloop_run_later, free);

    _eventloop_is_initialize = false;
}

int eventloop_run(void)
{
    assert(_eventloop_is_initialize);
    assert(!_eventloop_is_running);

    _eventloop_is_running = true;

    while (_eventloop_is_running)
    {
        eventloop_pump();
    }

    eventloop_uninitialize();

    return _eventloop_exit_value;
}

void eventloop_pump(void)
{
    assert(_eventloop_is_initialize);

    Handle *selected = NULL;
    SelectEvent selected_events = 0;

    Timeout timeout = UINT32_MAX;

    list_foreach(Timer, timer, _eventloop_timers)
    {
        if (timer->started && timer->interval != 0)
        {
            Timeout remaining = timer->interval - timer->elapsed;

            if (remaining < timeout)
            {
                timeout = remaining;
            }
        }
    }

    Result result = handle_select(
        &_eventloop_handles[0],
        &_eventloop_events[0],
        _eventloop_handles_count,
        &selected, &selected_events,
        timeout);

    eventloop_update_timers();

    if (result == SUCCESS)
    {
        list_foreach(Notifier, notifier, _eventloop_notifiers)
        {
            if (notifier->handle == selected)
            {
                notifier->callback(notifier->target, notifier->handle, selected_events);
            }
        }
    }
    else if (result == TIMEOUT)
    {
        // ignore
    }
    else
    {
        logger_error("Failled to select : %s", result_to_string(result));
    }

    list_foreach(RunLater, run_later, _eventloop_run_later)
    {
        run_later->callback(run_later->target);
    }
    list_clear_with_callback(_eventloop_run_later, free);
}

void eventloop_exit(int exit_value)
{
    assert(_eventloop_is_initialize);
    assert(_eventloop_is_running);

    _eventloop_is_running = false;
    _eventloop_exit_value = exit_value;
}

void eventloop_update_timers(void)
{
    assert(_eventloop_is_initialize);
    assert(_eventloop_is_running);

    TimeStamp current_fire = system_get_ticks();

    ElapsedTime elapsed = current_fire - _eventloop_timer_last_fire;

    list_foreach(Timer, timer, _eventloop_timers)
    {
        if (!timer->started)
        {
            continue;
        }

        timer->elapsed += elapsed;

        if (timer->elapsed >= timer->interval)
        {
            if (timer->callback)
            {
                timer->callback(timer->target);
            }

            timer->elapsed = 0;
        }
    }

    _eventloop_timer_last_fire = current_fire;
}

void eventloop_update_notifier(void)
{
    _eventloop_handles_count = 0;

    list_foreach(Notifier, notifier, _eventloop_notifiers)
    {
        _eventloop_handles[_eventloop_handles_count] = notifier->handle;
        _eventloop_events[_eventloop_handles_count] = notifier->events;

        _eventloop_handles_count++;
    }
}
void eventloop_register_notifier(Notifier *notifier)
{
    assert(_eventloop_is_initialize);

    list_pushback(_eventloop_notifiers, notifier);

    eventloop_update_notifier();
}

void eventloop_unregister_notifier(Notifier *notifier)
{
    assert(_eventloop_is_initialize);

    list_remove(_eventloop_notifiers, notifier);

    eventloop_update_notifier();
}

void eventloop_register_timer(struct Timer *timer)
{
    assert(_eventloop_is_initialize);

    list_pushback(_eventloop_timers, timer);
}

void eventloop_unregister_timer(struct Timer *timer)
{
    assert(_eventloop_is_initialize);

    list_remove(_eventloop_timers, timer);
}

void eventloop_run_later(RunLaterCallback callback, void *target)
{
    RunLater *run_later = __create(RunLater);

    run_later->callback = callback;
    run_later->target = target;

    list_pushback(_eventloop_run_later, run_later);
}

static IterationDecision cancel_run_later(void *target, RunLater *run_later)
{
    if (run_later->target == target)
    {
        list_remove(_eventloop_run_later, run_later);
    }

    return ITERATION_CONTINUE;
}

void event_cancel_run_later_for(void *target)
{
    list_iterate(_eventloop_run_later, target, (ListIterationCallback)cancel_run_later);
}
