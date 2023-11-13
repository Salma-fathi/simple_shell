#include "shell.h"


int is_builtin(char **command)
{
    char *builten[] = {
        "cd" , "exit" , "env" , "setenv" ,NULL
    };
    int j;
    for (j = 0; builten[j]; j++)
    {
        if (_strcmp(*command, builten[j]) == 0)
            return 1;
    }
    return 0;
}
void handl_built(int *status, char **command, int ind, char **argv)
{
    (void)argv;
    (void)ind;
    if (_strcmp(command[0], "exit") == 0)
        exit_shell(command, status);
    else if (_strcmp(command[0], "env") == 0)
        print_env(command, status);
}
void exit_shell(char **command ,int *status)
{
    int exit_val = *status;
    char *indx;
    if(command[1])
    {
        if(is_positive_num(command[1]))
        {
            exit_val = _itoa(command[1]);
        }
        else
        {
            indx = _itoa(ind);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
            write(STDERR_FILENO, indx, _strlen(indx));
			write(STDERR_FILENO, ": exit", 6);
			write(STDERR_FILENO, "Illegal number: ", 18);
			write(STDERR_FILENO, command, _strlen(command[1]));
			write(STDERR_FILENO, "\n", 1);
            free(indx);
            freearystring(command);
            return;
        }
    }
    freearystring(command);
    exit(exit_val);
}
void print_env(char **command, int *status)
{
    int i;
    for(i=0;environment[i];i++)
    {
        write(STDOUT_FILENO, environment[i], _strlen(environment[i]));
		write(STDOUT_FILENO, "\n", 1);
    }
    freearystring(command);
}