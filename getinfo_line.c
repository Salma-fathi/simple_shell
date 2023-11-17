#include "shell.h"
/**
 * _getline -function that reads the input
 * @linptr: the pointer to store the data
 * @n: the buffer size
 * @stream: the file to read the line from
 * Return: (0) on success and (-1) on failure
 */
size_t _getline(char **linptr, size_t *n, FILE *stream)
{
size_t l = 0;
int j;
char p;

	if (linptr == NULL || n == NULL || stream == NULL)
		{ return (-1); }

	if (*linptr == NULL)
	{
		*n = 15024;
		*linptr = malloc(*n);

		if (*linptr == NULL)
			{ return (-1); }
	}


	while ((j = read(fileno(stream), &p, 1)) == 1)
	{
		if (p == '\n')
			{ break; }

		(*linptr)[l++] = p;
	}

	if (j == 0)
		{ return (-1); }

	(*linptr)[l] = '\0';
	return (l);
}
