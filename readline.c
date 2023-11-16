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

    read_size = getline(&line, &buffer_size, stdin);
    if (read_size == -1) {
        free(line);
        return NULL;
    }
    if (line[read_size - 1] == '\n') {
        line[read_size - 1] = '\0';
    }

    return line;
}

