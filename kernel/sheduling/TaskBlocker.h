#pragma once

#include <libsystem/time.h>

struct Task;
struct TaskBlocker;

typedef bool (*TaskBlockerCanUnblockCallback)(struct TaskBlocker *blocker, struct Task *task);
typedef void (*TaskBlockerUnblockCallback)(struct TaskBlocker *blocker, struct Task *task);
typedef void (*TaskBlockerTimeoutCallback)(struct TaskBlocker *blocker, struct Task *task);

typedef enum
{
    BLOCKER_UNBLOCKED,
    BLOCKER_TIMEOUT,
} TaskBlockerResult;

typedef struct TaskBlocker
{
    TaskBlockerResult result;
    TimeStamp timeout;

    TaskBlockerCanUnblockCallback can_unblock;
    TaskBlockerUnblockCallback on_unblock;
    TaskBlockerTimeoutCallback on_timeout;
} TaskBlocker;

#define TASK_BLOCKER(__subclass) ((TaskBlocker *)(__subclass))
