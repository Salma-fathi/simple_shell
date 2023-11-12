#include "shell.h"
#include <string.h>

/**
 * _strtok - breaks the string into tokens
 * @str: string to be broken down
 * @del: separator
 * Return: pointer to the next token
 */
 char *_strtok(char *str, char *del)
{
    static char *lastToken = NULL;

    if (str != NULL)
    {
        lastToken = str;
    }
    else if (lastToken == NULL || *lastToken == '\0')
    {
        return NULL;
    }

    char *tokenStart = lastToken;
    char *tokenEnd = _strpbrk(tokenStart, del);

    if (tokenEnd != NULL)
    {
        *tokenEnd = '\0';
        lastToken = tokenEnd + 1;
    }
    else
    {
        lastToken = _strlen(lastToken);
    }

    return tokenStart;
}
