#include "shell.h"

/**
 * _putchar - function that writes the character p to stdout
 * Description: c programm
 * @p: The character to print
 * Return: On success 1 and On error -1 is returned
 */
int _putchar(char p)
{
	return (write(1, &p, 1));
}

/**
  * _puts - function print string
  * @str: input value
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str + 0);
		str++;
	}
	_putchar('\n');
}
