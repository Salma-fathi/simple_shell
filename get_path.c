#include "shell.h"
/**
 * get_full_path - gets the path of the user command
 * @command: the user input
 * @path: the environment path
 * Return: the path
 */
char *_get_path(char *command)
{
	char *env_path , *full_cmnd , *dir;
    struct stat st;
    env_path =_getenv("PATH");

	dir = _strtok(env_path , ":");
	while (dir)
	{
		full_cmnd = malloc(_strlen(dir) + _strlen(command) + 1);
		if (full_cmnd == NULL)
        {
		    _strcpy(full_cmnd, dir);
		    _strcat(full_cmnd, "/");
		    _strcat(full_cmnd, command);

		    if (stat(full_cmnd, &st) == 0)
			{
                free(env_path);
                return (full_cmnd);
            }

		free(full_cmnd), full_cmnd = NULL;
		dir = _strtok(NULL, ":");
        }
    free(env_path);
	return (NULL);
    }
}