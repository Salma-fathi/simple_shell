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
        Line =readline();
        if (Line == NULL)
        {
                    
            if(isatty(STDIN_FILEND))
                 write(STDOUT_FILEND,"\n", 1 )                      /* reache EOF ctr+d */
            return(status);
        }
        command = tokenzer(Line);
        if(!command)
            continus;
        for(i = 0; command[i] ; i++)
        {
            free(command[i]),command[i] = NULL;
        }
        free(command),command =NULL;
    }
}
