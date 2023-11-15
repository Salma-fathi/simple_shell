#include "shell.h"

/**
 * get_path - function that get the path of the command
 * Description: c programm
 * @command: command entered by user
 * Return: the path on success and 0 on failure
 */
char *get_path(char *cmnd, char **env)
{
    char **path_tokens;
    char *full_cmnd;
    struct stat st;
    int i = 0;

    path_tokens = tokenzer(get_env_val("PATH", env));
    if (!path_tokens)
        return NULL;

    while (path_tokens[i])
    {
        full_cmnd = malloc(sizeof(char) * (strlen(path_tokens[i]) + strlen(cmnd) + 2));
        if (!full_cmnd)
        {
            free_tokens(path_tokens);
            return NULL;
        }

        strcpy(full_cmnd, path_tokens[i]);
        strcat(full_cmnd, "/");
        strcat(full_cmnd, cmnd);

        if (stat(full_cmnd, &st) == 0)
        {
            free_tokens(path_tokens);
            return full_cmnd;
        }
        
        free(full_cmnd);
        i++;
    }

    free_tokens(path_tokens);
    return NULL;
}
