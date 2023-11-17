#include "shell.h"
/**
 * get_full_path - function that gets the path of the user command
 * @cmd: the user input
 * @path: the environment path
 * Return: on success the path and on failure 0
 */
char *get_full_path(char *cmd, char *path)
{
char *token, *full_path = NULL;
tokn = _strtok(path, ":");

	while (tokn != NULL)
	{
		full_path = malloc(_strlen(tokn) + _strlen(cmd) + 1);
		if (full_path == NULL)
			{ return (NULL); }

		_strcpy(full_path, tokn);
		_strcat(full_path, "/");
		_strcat(full_path, cmd);

		if (access(full_path, X_OK) == 0)
			{ return (full_path); }

		free(full_path);
		tokn = _strtok(NULL, ":");
	}

	return (NULL);
}
