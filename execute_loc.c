#include "shell.h"

int _execute(char **command ,char **argv , int ind)
{
    pid_t child;
    int status;
    char *full_cmnd;


    full_cmnd =_get_path(command[0]);
    if(!full_cmnd)
    {
        printerror(argv[0], command[0] , ind);
        freaarystring(command);
        return(127)
    }

    child =fork();
    if(child == 0)
    {
        if(execve(full_cmnd, command, envrioment) == -1)
        {
            free(full_cmnd) , full_cmnd = NULL;
            freaarystring(command);
        }
    }
    else
    {
        waitpid(child ,&status , 0);
        freaarystring(command);
        free(full_cmnd) , full_cmnd = NULL;


    }
    return(WEXITSTUTS(status));
    

}
