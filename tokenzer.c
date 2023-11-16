#include "shell.h"

/**
 * tokenzer - tokenizes a string into an array of strings
 * @Line: the string to tokenize
 * Return: the array of tokens
 */
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
    i = 0;
    j = 0; 
    while (token)
    {
        i++;
        token = _strtok(NULL, ARR);
    }

    command = malloc((i + 1) * sizeof(char *));
    if (!command)
    {
        free(tmp);
        return NULL;
    }

    free(tmp);
    tmp = _strdup(Line);

    token = _strtok(tmp, ARR);
    i = 0;
    while (i < i + 1 && (token = _strtok(NULL, ARR)))
    {
        command[i] = _strdup(token);
        if (!command[i])
        {
            for (j = 0; j < i; j++) 
                free(command[j]);
            free(command);
            free(tmp);
            return NULL;
        }
        i++;
    }

    command[i] = NULL;
    free(tmp);

    return command;
}

