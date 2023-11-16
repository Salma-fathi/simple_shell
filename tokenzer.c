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
    if (!token)
    {
        free(tmp);
        return NULL;
    }
    while (token)
    {
        command[i++] = _strdup(token);
        token = _strtok(NULL, ARR);
    }
    command[i] = NULL;
    for (int j = 0; j < i; j++)
        free(command[j]);
    free(command);
    free(tmp);

    return command;
}
