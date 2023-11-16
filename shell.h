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
extern char **environ;




int is_builtin(char **command);
void handle_built(int *status, char **command, int ind, char **argv);
void exit_shell(char **command, int *status);
void print_env(char **command);
/*                    */
char *read_line(void);
char **tokenzer(char *Line);
/*                     */
int _execute( char **name, char **argv, int ind,char *line);
void free_array_string(char **arry);
void printerror(char *name, char *command, int ind);

void rev_str(char *str, int len);
char *_itoa(int n);
int is_positive_num(char *str);
char *_strtok(char *str, char *del);
char *get_path(char *command,char *path);


/* fun string */
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strlen(char *s1);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
/*  */

void _free(char *f1, char **f2);

#endif
