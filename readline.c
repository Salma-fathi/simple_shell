#include "shell.h"

char *readline(void)
{
    char *Line = NULL;
    size_t Buff = 0;
    ssize_t r;
    if(isatty(STDIN_FILEND))
    write(STDOUT_FILEND," $" , 2);
    r = getline(&Line ,&Buff,stdin);
    if( n == -1)
    {
        free(Line);
        Return(NULL);
    }


    Return(Line);

}