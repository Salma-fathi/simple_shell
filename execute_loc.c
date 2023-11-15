#include "shell.h"

/**
 * exec - executes the user command
 * @argv: the array of the splited command
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
        freearystring(command);
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
        freearystring(command);
        free(full_cmnd);
    }
    return WEXITSTATUS(status);
}
#include "shell.h"

/**
 * _execute - executes the user command
 * @command: the array of the splited command
 * @argv: the name of the program
 * @ind: index
 */
void _execute(char **command, char **argv, int ind)
{
    pid_t child;
    int status;

    char full_cmnd[1024]; // Assuming the maximum length of a command path is 1024

    if (!get_path(command[0], full_cmnd))
    {
        printerror(argv[0], command[0], ind);
        freearystring(command);
        return;
    }

    child = fork();
    if (child == 0)
    {
        if (execve(full_cmnd, command, environ) == -1)
        {
            fprintf(stderr, "%s: %s: %s\n", argv[0], command[0], strerror(errno));
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(child, &status, 0);
        freearystring(command);
    }
}
