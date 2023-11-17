#include "shell.h"
/**
 * _getenv - function that get environment path
 * Description: c programm
 * @virn: the environment variable
 * Return: on success the path and on failure 0
 */
char *_getenv(char *virn)
{
size_t length = _strlen(virn);
char **env = environ;


	while (*env)
	{
		if (_strncmp(*env, virn, length) == 0 && (*env)[length] == '=')
			{ return (&(*env)[length + 1]); }
		env++;
	}
	return (NULL);
}
