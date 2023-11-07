#include "main.h"
/**
 * get_location - function that get avalue of the environment variables
 * Description: c programm
 * @command: command entered by User
 * Return: value of environment variables
 */
char *get_location(char *command)
{
char *path, *path_cpy, *path_token, *fil_path;
char *cmd_length, *dir_length;
path = getenv("PATH");
if (path)
{
	path_cpy = _strdup(path);
	cmd_length = _strlen(command);
	path_token = strtok(path_cpy, ":");

while (path_token != NULL)
{
	dir_length = _strlen(path_token);
	fil_path = malloc(cmd_length + dir_length + 2);
	_strcpy(fil_path, path_token);
	_strcat(fil_path, "/");
	_strcat(fil_path, command);
	_strcat(fil_path, "\0");
/* if (stat(fil_path, &buffer) == 0)*/
/*{*/
	/*free(path_cpy);*/
	/*return (fil_path)*/
/*else*/
/*{*/
/*	free(fil_path);*/
	/*path_token = strtok(NULL, ":");	}*/
	free(fil_path);
	path_token = strtok(NULL, ":"); }
	free(path_cpy);
/* if (stat(command, &buffer) == 0)*/
	/*{*/
	/*  return (command);*/
       /* }*/
	return (NULL); }
	return (NULL); }
