#include <libsystem/CString.h>
#include <libsystem/utils/BufferBuilder.h>
#include <libsystem/utils/SourceReader.h>

#include "shell/Nodes.h"

#define SHELL_WHITESPACE " \r\n\t"

static void whitespace(SourceReader *source)
{
    source_eat(source, SHELL_WHITESPACE);
}

static char *string(SourceReader *source)
{
    BufferBuilder *builder = buffer_builder_create(16);

    source_skip(source, '"');

    while (source_current(source) != '"' &&
           source_do_continue(source))
    {
        if (source_current(source) == '\\')
        {
            buffer_builder_append_str(builder, source_read_escape_sequence(source));
        }
        else
        {
            buffer_builder_append_chr(builder, source_current(source));
            source_foreward(source);
        }
    }

    source_skip(source, '"');

    return buffer_builder_finalize(builder);
}

static char *argument(SourceReader *source)
{
    if (source_current(source) == '"')
    {
        return string(source);
    }
    else
    {
        BufferBuilder *builder = buffer_builder_create(16);

        while (!source_current_is(source, SHELL_WHITESPACE) &&
               source_do_continue(source))
        {
            if (source_current(source) == '\\')
            {
                source_foreward(source);
            }

            if (source_do_continue(source))
            {
                buffer_builder_append_chr(builder, source_current(source));
                source_foreward(source);
            }
        }

        return buffer_builder_finalize(builder);
    }
}

static ShellNode *command(SourceReader *source)
{
    char *command_name = argument(source);

    whitespace(source);

    List *arguments = list_create();

    whitespace(source);

    while (source_do_continue(source) &&
           source_current(source) != '|' &&
           source_current(source) != '>')
    {
        list_pushback(arguments, argument(source));
        whitespace(source);
    }

    return shell_command_create(command_name, arguments);
}

static ShellNode *pipeline(SourceReader *source)
{
    List *commands = list_create();

    do
    {
        whitespace(source);
        list_pushback(commands, command(source));
        whitespace(source);
    } while (source_skip(source, '|'));

    if (list_count(commands) == 1)
    {
        ShellNode *node = (ShellNode *)list_peek(commands);
        list_destroy(commands);
        return node;
    }

    return shell_pipeline_create(commands);
}

static ShellNode *redirect(SourceReader *source)
{
    ShellNode *node = pipeline(source);

    whitespace(source);

    if (!source_skip(source, '>'))
    {
        return node;
    }

    whitespace(source);

    char *destination = argument(source);

    return shell_redirect_create(node, destination);
}

ShellNode *shell_parse(char *command_text)
{
    SourceReader *source = source_create_from_string(command_text, strlen(command_text));

    // Skip the utf8 bom header if present.
    source_skip_word(source, "\xEF\xBB\xBF");

    whitespace(source);

    ShellNode *node = redirect(source);

    source_destroy(source);

    return node;
}
