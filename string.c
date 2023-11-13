#include "shell.h"
#include <string.h>
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
	i++; }
	dest[i] = 0;
	return (dest); }
/**
 * *_strdup - function that duplicates a string
 * Description: c programm
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(char *str)
{
    int length = 0;
    char *d;
    
    if (str == NULL)
        return NULL;
    
    while (*str++)
        length++;
    
    d = malloc(sizeof(char) * (length + 1));
    if (d == NULL)
        return NULL;
    
    for (length++; length--;)
        d[length] = *--str;
    
    return d;
}
/**
 * _strlen - rfunctio that eturns the length of a string
 *  Description: c programm
 * @s1: the string whose length to check
 *
 * Return: integer length of string
 */
 char *_strlen(char *s1)
{
    size_t i = 0;
    if (!s1)
        return 0;
    while (*s1++)
        i++;
    return i;
}
/**
 * _strcat - function that concatenates two strings
 * Description: c programm
 * @dest: the destination buffer
 * @src: source
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
char *ret = dest;
while (*dest)
	dest++;
while (*src)
	*dest++ = *src++;
*dest = *src;
return (ret);
}
/**
 * _strcmp - compares 2 strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if it the same
 */
int _strcmp(char **s1, char **s2);
{
	int i = 0;
	while (s1[i] - s2[i] == 0 && s1[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
/**
 * _strchr - Returns a pointer to the first
 *       occurrence of the character
 * @s: string to search
 * @c: character to be searched for
 *
 * Return: the location
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
		{
			return (&s[i]);
		}
	}
	return (0);
}



