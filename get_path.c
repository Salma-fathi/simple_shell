#include "shell.h"
#include <stdlib.h>
#include <string.h>

char *get_path(char *command)
{
    char *env_path = getenv("PATH");
    char *dir;
    struct stat st;
    if (!env_path)
        return NULL;
    dir = strtok(env_path, ":");
    while (dir != NULL)
    {
        char *full_cmnd = (char *)malloc(strlen(dir) + strlen(command) + 2);
        if (!full_cmnd)
        {
            perror("malloc failed");
            return NULL;
        }

        strcpy(full_cmnd, dir);
        strcat(full_cmnd, "/");
        strcat(full_cmnd, command);

        if (stat(full_cmnd, &st) == 0)
            return full_cmnd;
        free(full_cmnd);
        dir = strtok(NULL, ":");
        dir = strtok(NULL, ":");
    }

    return NULL;
}
