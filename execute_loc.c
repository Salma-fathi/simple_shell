#include "shell.h"

int _execute(char **command, char **argv, int ind)
{
    pid_t child;
    int status;
    char *full_cmnd;

    full_cmnd = get_path(command[0]);

    if (!full_cmnd)
    {
        printerror(argv[0], command[0], ind);
        freaarystring(command);
        return(127);
    }

    child = fork();
    if (child == 0)
    {
        if (execve(full_cmnd, command, enviroment) == -1)
        {
            perror("Error");
            free(full_cmnd);
            freaarystring(command);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(child, &status, 0);
        freaarystring(command);
        free(full_cmnd);
    }

    return WEXITSTATUS(status);
}

