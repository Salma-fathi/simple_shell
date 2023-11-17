#include "shell.h"

/**
 * exec - function that xecutes the user command
 * @arry: array of the splited command
 * @lin: input of the user
 * @name: shell name
 * @index: the index
 * Return: status of the operation
 */
int exec(char **arry, char *lin, int index, char **name)
{
int status = 0;
char *path = NULL, *command;
pid_t id = fork();


	if (id == 0)
	{
		if (_strchr(arry[0], '/') == NULL)
		{
			path = _getenv("PATH");
			command = get_full_path(arry[0], path);
			if (command == NULL)
			{
				print_error(name[0], arry[0], index);
				return (127);
			}
		}
		else
			{ command = arry[0]; }
		if (execve(command, arry, environ) == -1)
		{
			free(arry);
			free(lin);
			exit(127);
		}
	}
	else
		{ waitpid(id, &status, 0); }
	return (WEXITSTATUS(status));
}
