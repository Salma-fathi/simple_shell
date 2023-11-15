#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
  * _getenv - function that gets the environment variable value
  * @var: variable name
  * Return: the value of the environment variable, or NULL if not found
  */
char *_getenv(char *var)
{
    int i;
    char *tmp, *value, *keey, *env;
    if (var == NULL)
        return NULL;
    for (i = 0; environ[i] != NULL; i++)
    {
        tmp = _strdup(environ[i]);
        if (tmp == NULL)
        {
            return NULL;
        }

        keey = _strtok(tmp, "=");
        if (keey != NULL && _strcmp(var, keey) == 0)
        {
            value = _strtok(NULL, "\n");
            env = _strdup(value);
            free(tmp);

            if (env == NULL)
            {
                return NULL;
            }

            return env;
        }

        free(tmp);
        tmp = NULL;
    }

    return NULL;
}
