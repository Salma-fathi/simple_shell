#include "shell.h"

/**
 * _strtok - function that breaks the string into tokensing
 * Description: c programm
 * @delm: the separator
 * @string: the string
 * Return: poiner to the next token
 */
char *_strtok(char *string, char *delm)
{
	static char *tokn;
	char *toknizer;

	if (string != NULL)
		{ tokn = string; }

	if (tokn == NULL)
		{ return (NULL); }

	while (*tokn != '\0' && _strchr(delm, *tokn) != NULL)
		tokn++;

	if (*tokn == '\0')
		{ return (NULL); }

	toknizer = tokn;
	while (*tokn != '\0' && _strchr(delm, *tokn) == NULL)
		tokn++;
	if (*tokn != '\0')
	{
		*tokn = '\0';
		tokn++;
	}
	return (toknizer);
}
