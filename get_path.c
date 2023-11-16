#include "shell.h"

/**
 * get_path - function that gets the path of the command
 * Description: C program
 * @command: command entered by the user
 * Return: the path on success and NULL on failure
 */
char *get_path(char *command)
{
    char *env_path = getenv("PATH");
    char *dir;
    struct stat st;

    if (!env_path)
    {
        return NULL;
    }

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
        {
            return full_cmnd;
        }
        free(full_cmnd);
        dir = strtok(NULL, ":");
    }
    return NULL;
}
