#include "shell.h"
/**
 * main - entry point
 * @ac: counts argumnents number
 * @argv: array of string
 * Return: 0 always (success)
 */
 int main(int ac,char **argv)
{
    char *Line = NULL;
    char **command =NULL;
    int status;
    (void) ac;


    while (1)
    {
        Line = readline();
        if (Line == NULL)
        {
                    
            if(isatty(STDIN_FILENDO))
                write(STDOUT_FILENDO,"\n", 1 );                     /* reache EOF ctr+d */
            return(status);
        }
        command = tokenzer(Line);
        if(!command)
            continue;
        status =_execute(command,argv);
        
    }
}
