#include "shell.h"
/**
 * _isempty - function that check if the user give empty input
 * @string: input of the user
 * Return: if true return 1 if false return 0
 */
int _isempty(const char *string)
{
	if (string == NULL)
		{ return (1); }
	while (*string)
	{
		if (!_isspace(*string))
			{ return (0); }
		string++;
	}
	return (1);
}
/**
 * _isspace - function that check the character of input
 * @m: character of input
 * Return: 0 if false and 1 if true
 */
int _isspace(char m)
{
	return (m == ' ' || m == '\t' || m == '\n' ||
		m == '\v' || m == '\f' || m == '\r');
}
