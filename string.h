#include "main.h"

/**
 * _strcpy - copies string two into string one string
 * Description: c programm
 *  @dest: the destination
 * @src: the source
 *
 * Return: pointer to the destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	d = malloc(sizeof(char) * (length + 1));
	if (!d)
		return (NULL);
	for (length++; length--;)
		d[length] = *--str;
	return (d);
}
