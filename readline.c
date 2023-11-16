#include "shell.h"
#include <stdio.h>
/**
 * read_line - read the line from user
 * Description: c programm
 * Return: return the line from user
 */
char *read_line(void)
{
    char *line = NULL;
    size_t buffer = 0;
    ssize_t read_size;

    if (isatty(STDIN_FILENO))
    {
        write(STDOUT_FILENO, "$ ", 2);
        fflush(stdout);
    }
    read_size = getline(&line, &buffer, stdin);
    if (read_size <= 0)
    {
        free(line);
        return NULL;
    }
    return line;
}

