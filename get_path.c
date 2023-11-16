#include "shell.h"

/**
 * get_path - function that gets the path of the command
 * Description: C program
 * @command: command entered by the user
 * Return: the path on success and NULL on failure
 */

char *get_path(char *command)
{
	char *token;
	char *full_path = NULL;
	token = _strtok(path, ":");
	while (token != NULL)
	{
		full_path = malloc(_strlen(token) + _strlen(command) + 2);
		if (full_path == NULL)
			return (NULL);

		_strcpy(full_path, token);
		_strcat(full_path, "/");
		_strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
			return (full_path);

		free(full_path);
		token = _strtok(NULL, ":");
	}

	return (NULL);
}