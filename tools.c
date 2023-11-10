#include "shell.h"


void freaarystring(char **arry)
{
    int i;
    if(!arry)
        return;

    for(i = 0; array[i] ; i++)
        {
        free(arry[i]),arry[i] = NULL;
        }
    free(arry),arry =NULL;

}

/**
 * print_error - displays error message
 * @name: shell name
 * @command: user command
 * @ind: error index
 */
void printerror(char *name, char *command, int ind)
{
	char *id, msg[] = ": not found\n";

	id = _itoa(ind);
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, id, _strlen(id));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, msg, _strlen(msg))
	free(id);
}

/**
 * _itoa - change the int to char
 * @n:the int number
 * Return: the char
 */
char *_itoa(int n)
{
	char buffer[30];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	rev_str(buff, i);

	return (_strdup(buffer));
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