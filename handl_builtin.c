#include "shell.h"
/**
 * is_builtin - function that determinr if the command built in or not
 * Description: c programm
 * @command: command entered by user
 * Return: on success 1  on failure 0
 */

int is_builtin(char **command)
{
	int i;
    if (!command || !command[0])
    {
        return 0;
    }

    char *builtins[] = {"exit", "env", "setenv", "cd", NULL};

    for (i = 0; builtins[i]; i++)
    {
        if (_strcmp(command[0], builtins[i]) == 0)
        {
            return (1);
        }
    }

    return (0);
}
/**
 * handle_built - function that adds the built in command
 * Description: c programm
 * @command: command entered by user
 * @status: status of the command
 * @ind: the index
 * @argv: argument vector
 * Return: nothing
 */
void handle_built(int *status, char **command, int ind, char **argv)
{
	(void)argv;
	(void)ind;
	if (_strcmp(command[0], "exit") == 0)
		{ exit_shell(command, status); }
	else if (_strcmp(command[0], "env") == 0)
		{ print_env(command); }

}

/**
 * exit_shell - function that exits the shell
 * Description: C program
 * @command: command entered by the user
 * @status: status of the command
 * Return: nothing
 */
void exit_shell(char **command, int *status)
{
    int exit_val = *status;
    char *indx = NULL;
    int ind;

    if (command[1])
    {
        if (is_positive_num(command[1]))
        {
            exit_val = atoi(command[1]);
        }
        else
        {
            ind = 0;
            indx = _itoa(ind);
            write(STDERR_FILENO, command[0], (size_t)_strlen(command[0]));
            write(STDERR_FILENO, indx, (size_t)_strlen(indx));
            write(STDERR_FILENO, ": ", 2);
            write(STDERR_FILENO, ": exit: Illegal number: ", 24);
            write(STDERR_FILENO, command[1], (size_t)_strlen(command[1]));
            write(STDERR_FILENO, "\n", 1);

            free(indx);
            free_array_string(command);
            return;
        }
    }

    free_array_string(command);
    free(indx);
    exit(exit_val);
}

/**
 * print_env - function that print the environment
 * Description: c programm
 * @command: command entered by user
 * Return: nothing
 */
void print_env(char **command)
{
int i;
for (i = 0; environ[i]; i++)
{
	write(STDOUT_FILENO, environ[i], (size_t)_strlen(environ[i]));
	write(STDOUT_FILENO, "\n", 1);
}
free_array_string(command);

}
