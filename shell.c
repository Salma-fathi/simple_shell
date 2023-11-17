#include "shell.h"

/**
 * main - entry point
 * Description: c programm
 * @ac: counts arg number
 * @argv: array of string
 * Return: 0 in success and -1 in fail
 */
int main(int ac, char **argv)
{
char *lin = NULL, **tokns = NULL, **toknizer = NULL;
int status = 0, index = 0, j;
(void) ac;


	while (1)
	{
		lin = read_line();

		if (lin == NULL)
			return (status);
		_comment(lin);
		if (_isempty(lin))
		{
			free(lin), status = 0;
			continue;
		}
		index++;
		toknizer = spilt_line(lin, ";");

		if (toknizer == NULL)
			continue;
		for (j = 0; toknizer[j] != NULL; j++)
		{
			tokns = spilt_line(toknizer[j], " \n\t");
			if (tokns == NULL)
			{
				free(tokns);
				continue;
			}
			if (check_built(lin))
			{
				handle_built(tokns, status, lin, index, argv, toknizer);
				continue;
			}
			status = _exec(tokns, lin, index, argv);
			free(tokns);
		}
		free(toknizer), free(lin);
	}

	return (status);
}
