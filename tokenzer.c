#include "shell.h"

char **tokenzer(char *Line)
{
    char *token;
    char **command = NULL;
    int i = 0;
    char *tmp = NULL;

    if (!Line)
        return NULL;

    tmp = _strdup(Line);

    token = _strtok(tmp, ARR);
    if (!token)
    {
        free(Line);
        free(tmp);
        return NULL;
    }


    while (token)
    {
        i++;
        token = _strtok(NULL, ARR);
    }

    
    command = malloc((i + 1) * sizeof(char *));
    if (!command)
    {
        free(Line);
        free(tmp);
        return NULL;
    }

    
    token = _strtok(Line, ARR);
    i = 0;
    while (token)
    {
        command[i++] = token;
        token = _strtok(NULL, ARR);
    }

    free(Line);
    free(tmp);
    command[i] = NULL;
    return command;
}

