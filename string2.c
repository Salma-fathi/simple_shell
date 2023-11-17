#include "shell.h"
/**
 * _strchr - function that Returns a pointer to the first
 * occurrence of the character
 * Description: c programm
 * @s: string to search
 * @c: character to be searched for.
 * Return: the location on success and 0 on failure
 */

char *_strchr(char *str, char c)
{
	int j;

	for (j = 0; str[j] != '\0'; j++)
	{
		if (str[i] == c)
		{
			return (&str[i]);
		}
	}
	return (0);
}

/**
 * *_strdup - function that duplicate the string
 * Description: c programm
 * @string: input
 * Return: pointer
 */

char *_strdup(char *string)
{
int j;
int size;
char *n;

	if (string == NULL)
                { return (NULL); }

        for (size = 0; string[size] != '\0'; size++)
                ;
        size++;
        n = malloc(size * sizeof(*string));

        if (n == 0)
                { return (NULL); }
        for (j = 0; j < size; j++)
                n[j] = string[j];
        return (n);
}

