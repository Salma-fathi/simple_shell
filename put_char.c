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
  * _puts - function that  print string
  * Description: c programm
  * string: input value
  * Return: nothing
  */
void _puts(char *string)
{
	while (*string != '\0')
	{
		_putchar(*string + 0);
		string++;
	}
	_putchar('\n');
}
