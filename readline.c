#include "shell.h"


char *read_line(void)
{
    char *line = NULL;
    size_t buffer = 0;
    ssize_t readsize;

    if (isatty(STDIN_FILENO))
    {
        write(STDOUT_FILENO, "$ ", 2);
        fflush(stdout);
    }

    readsize = getline(&line, &buffer, stdin);

    if (read_size <= 0)
    {
        free(line);
        return NULL;
    }

    return line;
}


