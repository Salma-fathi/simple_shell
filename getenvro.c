#include "shell.h"
#include <string.h>
/**
 * _getenv - gets environment path
 * @var: the env variable
 * Return: the path
 */
char *_getenv(char *var)
{
	size_t len = _strlen(var);
	char **env = environ;

	while (*env)
	{
		if (_strncmp(*env, var, len) == 0 && (*env)[len] == '=')
			return (&(*env)[len + 1]);
		env++;
	}
	return (NULL);
}