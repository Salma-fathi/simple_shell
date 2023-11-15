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
