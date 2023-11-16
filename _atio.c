#include "shell.h"
/**
 * _atoi_ - convert the char to int
 * @str: the string we want to convert it
 * Return: the converted int
 */
int _atoi_(char *str)
{
	int rel= 0;
	int i, j;

	i = _strlen(str);
	for (j = 0; j< i; j++)
	{
		if (str[j] < '0' || str[j] > '9')
			break;
		result = result * 10 + str[j] - '0';
	}
	return (rel);
}