#include "shell.h"

/**
 * exec - executes the user command
 * @arg: the array of the splited command
 * @line: the input of the user
 * @name: shell name
 * @ind: index
 * Return: the status of the operation
 */

int _execute(char **command, char **argv, int ind)
{
    pid_t child;
    int status;
    char *full_cmnd;

    full_cmnd = get_path(command[0]);
    if (!full_cmnd)
    {
        printerror(argv[0], command[0], ind);
        free_array_string(command);
        return 127;
    }

    child = fork();
    if (child == 0)
    {
        if (execve(full_cmnd, command, environ) == -1)
        {
            perror("execve failed");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    }
    else
    {
        waitpid(child, &status, 0);
        free_array_string(command);
        free(full_cmnd);
    }
    return WEXITSTATUS(status);
}
