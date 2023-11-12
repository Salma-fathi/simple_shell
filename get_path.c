#include "shell.h"
/**
 * get_path - gets the path of the user command
 * @command: the user input
 * Return: the path if found, otherwise NULL
 */
char *get_path(char *command)
{
    char *env_path, *full_cmnd, *dir;
    struct stat st;

    env_path = _getenv("PATH");
    if (env_path == NULL) {
        return NULL;
    }

    dir = _strtok(env_path, ":");
    while (dir)
    {
        full_cmnd = malloc(_strlen(dir) + _strlen(command) + _strlen("/") + 1);
        if (full_cmnd == NULL)
        {
            free(env_path);
            return NULL;
        }
        _strcpy(full_cmnd, dir);
        _strcat(full_cmnd, "/");
        _strcat(full_cmnd, command);

        if (stat(full_cmnd, &st) == 0)
        {
            free(env_path);
            return full_cmnd;
        }

        free(full_cmnd);
        dir = _strtok(NULL, ":");
    }

    free(env_path);
    return NULL;
}
