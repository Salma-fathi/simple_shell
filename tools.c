#include "shell.h"
#include <string.h>

void freearystring(char **arry)
{
    int i;
    if (!arry)
        return;

    for (i = 0; arry[i]; i++)
    {
        free(arry[i]);
        arry[i] = NULL;
    }
    free(arry);
    arry = NULL;
}

void printerror(char *name, char *command, int ind)
{
    char *id, msg[] = ": not found\n";

    id = _itoa(ind);
    write(STDERR_FILENO, name, strlen(name));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, id, strlen(id));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, command, strlen(command));
    write(STDERR_FILENO, msg, strlen(msg));
    free(id);
}

char *_itoa(int n)
{
    char bufr[20];
    int i = 0;

    if (n == 0)
        bufr[i++] = '0';
    else
    {
        while (n > 0)
        {
            bufr[i++] = (n % 10) + '0';
            n /= 10;
        }
    }
    bufr[i] = '\0';
    rev_str(bufr, i);

    return _strdup(bufr);
}

void rev_str(char *str, int len)
{
    int begin = 0, end = len - 1;
    char copy;

    while (begin < end)
    {
        copy = str[begin];
        str[begin] = str[end];
        str[end] = copy;
        begin++;
        end--;
    }
}


int is_positive_num(char *str)
{
    int i;

    if(!str)
        return 0;
    for(i =0 ;str[i];i++)
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}