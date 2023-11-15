#include "shell.h"

/**
 * main - entry point
 * @ac: counts argumnents number
 * @argv: array of string
 * Return: 0 always (success)
 */

int main(int ac, char **argv)
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
