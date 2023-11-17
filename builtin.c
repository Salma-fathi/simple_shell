#include "shell.h"
/**
 * check_built - function that check if the user input is built in function
 * @cmd: the input command
 * Return: 1 on success  and 0 on failure
 */

int check_built(char *cmd)
{
	char *built_function[] = {"exit", "cd", "env", NULL};
	int j;

	for (j = 0; built_function[j]; j++)
	{
		if (_strcmp(cmd, built_function[j]) == 0)
			return (1);
	}

	return (0);
}

/**
 * handle_built - handle the built in function
 * @arry:  array of spilted command
 * @status: the status of operation
 * @cmd: the user input
 * @index: the index of process
 * @argv: - the argument of main function
 * @tokenizer: the array were sparated by ;
 */
void handle_built(char **arry, int status, char *cmd, int index,
char **argv, char **tokenizer)
{
int j = 0;
char *ID = NULL;

	if (_strcmp(arry[0], "exit") == 0)
	{
		if (arry[1])
			status = _atoin(arry[1]);
		else
			free(tokenizer), _free(cmd, arry), exit(status);
		if (arry[1][0] == '-')
		{
			ID = _itoa(index);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, ID, _strlen(ID));
			write(STDERR_FILENO, ": exit", 6);
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, "Illegal number: ", 16);
			write(STDERR_FILENO, arry[1], _strlen(arry[1]));
			write(STDERR_FILENO, "\n", 1);
			_free(cmd, arry), free(ID), exit(2);
		}
		_free(cmd, arry), free(tokenizer), free(ID);
		exit(status);
	}
	else if (_strcmp(arry[0], "env") == 0)
	{
		for (j = 0; environ[j]; j++)
		{
			write(STDOUT_FILENO, environ[j], _strlen(environ[j]));
			write(STDOUT_FILENO, "\n", 1);
		}
		free(arry);
	}
}

/**
 * _free - function that free two element
 * @f: the first element
 * @f1: the second elment
 */
void _free(char *f, char **f1)
{
		free(f);
		free(f1);
}
