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
