#include "shell.h"
/**
 * read_line - function that read the line from user
 * Description: c programm
 * Return: the line from user
 */
char *read_line(void)
{
char *new_lin = NULL;
size_t buff_length = 0;
ssize_t chars;

	if (isatty(STDIN_FILENO))
		{ write(1, "$ ", 2); }

	chars = _getline(&new_lin, &buff_length, stdin);
	if (chars == -1)
	{
		if (isatty(STDIN_FILENO))
			{ write(1, "\n", 1); }
		free(new_lin);
		return (NULL);
	}
	return (new_lin);
}
