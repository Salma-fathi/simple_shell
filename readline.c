#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * read_line - read the line from user
 * Description: c programm
 * Return: return the line from user
 */
char *read_line(void)
{
    char *line = NULL;
    size_t buffer_size = 0;
    ssize_t read_size;

    read_size = getline(&line, &buffer, stdin);
    if (read_size <= 0)
    {
        free(line);
        return NULL;
    }
    free(line);
    return line;
}

