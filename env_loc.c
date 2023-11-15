#include "main.h"
/**
 * get_path - function that get avalue of the environment variables
 * Description: c programm
 * @command: command entered by User
 * Return: value of environment variables
 */
char *get_path(char *command)
{
char *path, *path_cpy, *path_token, *fil_path;

path = getenv("PATH");
if (path)
{
	path_cpy = _strdup(path);
	path_token = strtok(path_cpy, ":");

while (path_token != NULL)
{
	fil_path = malloc(sizeof(char *));
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
