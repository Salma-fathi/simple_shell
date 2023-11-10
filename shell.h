#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define ARR "\t\n"

char *readline(void);

/*fun string*/
char _strdup(char *str);
char _strcmp( char *s1,char s2);
int  _strlen(char *s);
char _strcat( char *dest,char *src);
char _strcpy( char *dest,char *src);

#endif