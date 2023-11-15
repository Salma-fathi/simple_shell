#include "shell.h"

/**
 * exec - executes the user command
 * @arg: the array of the splitted command
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
    }
    else if (child == -1)
    {
        perror("fork failed");
        free(full_cmnd);
        free_array_string(command);
        return -1;
    }
    else
    {
        waitpid(child, &status, 0);
        free(full_cmnd);
        free_array_string(command);
        return WEXITSTATUS(status);
    }
}
