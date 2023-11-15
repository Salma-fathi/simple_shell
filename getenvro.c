#include "shell.h"

char *_getenv(char *var)
{
    char *tmp, *value, *key, *env;
    int i;

    for (i = 0; environ[i]; i++)
    {
        tmp = _strdup(environ[i]);
        key = _strtok(tmp, "=");
        if (_strcmp(var, key) == 0)
        {
            value = _strtok(NULL, "\n");
            env = _strdup(value);
            free(tmp);
            return env;
        }
        free(tmp);
        tmp = NULL;
    }
    return NULL;
}