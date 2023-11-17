#include "shell.h"
/**
 * spilt_line - function that splits the command entered from the user
 * @new_lin: input from user
 * @delm: the delimeter
 * Return: the array of the splited command
 */
char **spilt_line(char *new_lin, char *delm)
{
	int length = 0;
	char **arg = NULL, *tokn = NULL;

	arg = malloc(sizeof(char *) * 25);
	if (arg == NULL)
		{ return (NULL); }
	tokn = _strtok(new_lin, delm);
	if (!tokn)
	{
		free(new_lin);
		return (NULL);
	}
	while (tokn != NULL)
	{
		arg[length] = tokn;
		length++;
		tokn = _strtok(NULL, delm);
	}
	arg[length] = NULL;
	return (arg);
}
