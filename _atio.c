#include "shell.h"
/**
 * _atoin - function that convert the char to integer
 * Description: c programm
 * @string:  string we want to convert it
 * Return: return the converted integer
 */
int _atoin(char *string)
{
	int res= 0, m, n;

	m = _strlen(string);
	for (n = 0; n< m; n++)
	{
		if (string[n] < '0' || string[n] > '9')
		{
			break;
		}
		res = res * 10 + string[n] - '0';
	}

	return (res);
}
