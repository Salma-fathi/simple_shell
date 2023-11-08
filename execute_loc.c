#include "shell.h"

int _execute(char **command ,char **argv)
{
    pid_t child;
    int status;

    child =fork();
    if(child == 0)
    {
        if(execve(command[0], command, envrioment) == -1)
        {
            perror(argv[0]);
        }
    }
    else
    {
        waitpid(child ,&status , 0);
    }
    return(EXIT(status))

}
