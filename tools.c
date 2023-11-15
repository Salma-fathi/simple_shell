#include "shell.h"

freeeaarystring(char **arry)
{
    int i;
    if(!arry)
        return;

    for(i = 0; array[i] ; i++)
        {
        free(arry[i]),arry[i] = NULL;
        }
    free(arry),arry =NULL;
}
