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
        size_t len_dir = strlen(dir);
        size_t len_command = strlen(command);
        char *full_cmnd = malloc(len_dir + len_command + 2);

        if (!full_cmnd)
        {
            perror("malloc failed");
            return NULL;
        }

        snprintf(full_cmnd, len_dir + len_command + 2, "%s/%s", dir, command);

        if (stat(full_cmnd, &st) == 0)
        {
            return full_cmnd;
        }

        free(full_cmnd);
        dir = strtok(NULL, ":");
    }

    return NULL;
}
