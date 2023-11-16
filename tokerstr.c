#include "shell.h"
#include <string.h>

/**
 * _strtok - breaks the string into tokens
 * @str: string to be broken down
 * @del: separator
 * Return: pointer to the next token
 */
char *_strtok(char *str,char *delim)
{
    static char *lastToken = NULL;
    char *token;

    if (str)
        lastToken = str;

    if (!lastToken || !delim || !(*lastToken))
        return NULL;

    token = lastToken;

    while (*lastToken && !strchr(delim, *lastToken))
        lastToken++;

    if (*lastToken)
    {
        *lastToken = '\0';
        lastToken++;
    }

    return token;
}