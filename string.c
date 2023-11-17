#include "shell.h"

/**
 * _strncmp - compare two strings
 * Description: c programm
 * @s1: the first string
 * @s2: the second string
 * @numb: size
 * Return: comparsion
 */
int _strncmp(const char *s1, const char *s2, size_t numb)
{
size_t j;

	for (j = 0; j < numb; j++)
	{
		if (s1[j] == '\0' || s1[j] != s2[j])
		{
			return (s1[j] - s2[j]);
		}
	}

	return (0);
}
/**
 *  _strlen - function that print length of string
 *  Description: c programm
 *  @s: the string
 *  Return: length of the enterde string
 */
int _strlen(char *s)
{
	int length = 0, j;

	for (j = 0; s[j] != '\0'; j++)
		{
		length++;
		}
	return (length);
}

/**
 * _strcat - function that concatenates 2 strings
 * Description: c programm
 * @dest: string to be appended to
 * @src: string to append
 * Return: the concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int m = 0, n;

	while (dest[m] != '\0')
	{
		m++;
	}
	for (n = 0; src[n] != '\0'; n++)
	{
		dest[m + n] = src[n];
	}
	dest[m + n] = '\0';
	return (dest);
}

/**
 * *_strcpy - function that copies the string pointed to by s1
 * including the terminating null byte (\0)
 * to the buffer pointed to by s2
 * Description: c programm
 * @s1: pointer to the buffer in which we copy the string
 * @s2: string to be copied
 * Return: the copied string
 */
char *_strcpy(char *s1, char *s2)
{
	int len = 0, j;

	while (s2[len] != '\0')
	{
		len++;
	}

	for (j = 0; j < len; j++)
	{
		s2[j] = s1[j];
	}
	s2[j] = '\0';
	return (s2);
}

/**
 * _strcmp - function that compares 2 strings
 * Description: c programm
 * @str1: first string
 * @str2: second string
 * Return: 0 if it the same
 */
int _strcmp(char *str1, char *str2)
{
int j = 0;


	while (str1[j] - str2[j] == 0 && str1[j] != '\0')
	{
		j++;
	}
	return (str1[j] - str2[j]);
}
