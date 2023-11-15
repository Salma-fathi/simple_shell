#include "shell.h"
<<<<<<< HEAD
/**
 * main - entry point
 * @ac: counts argumnents number
 * @argv: array of string
 * Return: 0 always (success)
 */
int main(int ac,char **argv)
=======

int main(int ac, char **argv)
>>>>>>> 14cbd4c6c5d0efd06dcd8107dc403cbfaa1dc80c
{
    char *Line = NULL;
    char **command = NULL;
    int status = 0, ind = 0;
    (void) ac; 

    while (1)
    {
        Line = read_line();
        if (Line == NULL)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            /* reaches EOF (Ctrl+D) */
            return status;
        }
        ind++;

        command = tokenzer(Line);
        if (!command)
            continue;
        if (is_builtin(command))
            handle_built(&status, command, ind, argv);
        else
            status = _execute(command, argv, ind);
    }
}
