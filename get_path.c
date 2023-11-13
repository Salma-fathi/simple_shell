#include "shell.h"

char *get_path(char *command)
{
    char *env_path = _getenv("PATH");
    if (!env_path)
        return NULL;

    char *dir = strtok(env_path, ":");
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

        struct stat st;
        if (stat(full_cmnd, &st) == 0)
            return full_cmnd;
        free(full_cmnd);
        dir = strtok(NULL, ":");
    }

    return NULL;
}