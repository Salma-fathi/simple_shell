#include "shell.h"

void handle_built(int *status, char **command, int ind, char **argv)
{
    (void)argv;
    (void)ind;
    if (_strcmp(command[0], "exit") == 0)
        exit_shell(command, status);
    else if (_strcmp(command[0], "env") == 0)
        print_env(command);

}

void exit_shell(char **command, int *status)
{
    int exit_val = **status;
    char *indx;
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
            freearystring(command);
            return;
        }
    }
    freearystring(command);
    exit(exit_val);
}
void print_env(char **command)
{
    int i;
    for (i = 0; environ[i]; i++)
    {
        write(STDOUT_FILENO, environ[i], (size_t)_strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
    }
    freearystring(command);
}