#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


#define ARR "\t\n"
extern char **enviroment;


char *readline(void);
char **tokenzer;(char *Line)

int _execute(char **command ,char **argv , int ind)
void freaarystring(char **arry)

void printerror(char *name, char *command, int ind)
void rev_str(char *str, int len)
char *_itoa(int n)




/*fun string*/
char _strdup(char *str);
char _strcmp( char *s1,char s2);
int  _strlen(char *s);
char _strcat( char *dest,char *src);
char _strcpy( char *dest,char *src);

#endif