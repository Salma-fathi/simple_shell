#include "shell.h"
/**
 * comment - function that handles the comments from the user
 * Description: c programm
 * @lin: the input from user
 * Return: nothing
 */

void comment(char *lin)
{
	int m = 0;


	if (line[m] == '#')
		{ (lin[m]) = '\0'; }
	while (lin[m] != '\0')
	{
		if (lin[m] == '#' && lin[m - 1] == ' ')
			{ break; }
		m++;
	}
	lin[m] = '\0';
}
