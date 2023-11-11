#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <ctype.h>

#define ARR "\t\n"
extern char **environment;

char *readline(void);
char **tokenzer(char *Line);
/*                     */
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strncmp(char *str1, char *str2, size_t n);

char _execute(char **command, char **argv, int ind);
void freearystring(char **array);
void printerror(char *name, char *command, int ind);
void rev_str(char *str, int len);
char *_itoa(int n);

char *_strtok(char *str, char *del);
char *get_path(char *command);

/* fun string */
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strlen(char *s1);
char _strdup(char *str);
char *_strcpy(char *dest, char *src);

#endif
