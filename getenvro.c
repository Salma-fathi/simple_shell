#include "shell.h"
/**
 * _getenv - function that get environment path
 * Description: c programm
 * @viron: the environment variable
 * Return: on success the path and on failure 0
 */
char *_getenv(char *viron)
{
size_t length = _strlen(viron);
char **env = environ;


	while (*env)
	{
		if (_strncmp(*env, viron, length) == 0 && (*env)[length] == '=')
			{ return (&(*env)[length + 1]); }
		env++;
	}
	return (NULL);
}
