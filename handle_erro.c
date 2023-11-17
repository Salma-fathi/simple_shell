#include "shell.h"
/**
 * print_error - function that displays error message
 * @name: shell name
 * @cmd: the user command
 * @index: error index
 * Return: nothing
 */
void print_error(char *name, char *cmd, int index)
{
	char *id, messg[] = ": not found\n";

	id = _itoa(ind);
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, id, _strlen(id));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));

	write(STDERR_FILENO, messg, _strlen(messg));
	free(id);
}

/**
 * _itoa - function that change the int to char
 * Description: c programm
 * @m:the integer number
 * Return: the character
 */
char *_itoa(int m)
{
	char buf[25];
	int j = 0;

	if (m == 0)
		{ buf[j++] = '0';  }
	else
	{
		while (m > 0)
		{
			buf[j++] = (m % 10) + '0';
			m /= 10;
		}
	}
	buf[j] = '\0';
	rev_str(buf, j);

	return (_strdup(buf));
}

/**
 * rev_str - function that reverse string
 * @string: the string to be reverted
 * @length: the string length
 * Return: nothing
 */
void rev_str(char *string, int length)
{
	int beg = 0, end = length - 1;
	char copy;

	while (beg < end)
	{
		copy = string[beg];
		string[beg] = string[end];
		string[end] = copy;
		beg++;
		end--;
	}
}
