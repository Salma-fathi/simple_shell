#include "shell.h"
/**
 * print_error - function that displays error message
 * @name: shell name
 * @cmd: the user command
 * @ind: error index
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
 * _itoa - change the int to char
 * @m:the int number
 * Return: the char
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
			buf[j+] = (m% 10) + '0';
			m /= 10;
		}
	}
	buf[j] = '\0';
	rev_str(buf, j);

	return (_strdup(buf));
}

/**
 * rev_str - reverse string
 * @str: string to be reverted
 * @len: string length
 */
void rev_str(char *str, int len)
{
	int begin = 0, end = len - 1;
	char copy;

	while (begin < end)
	{
		copy = str[begin];
		str[begin] = str[end];
		str[end] = copy;
		begin++;
		end--;
	}
}
