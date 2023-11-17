#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <ctype.h>


extern char **environ;
char *read_line(void);
char **spilt_line(char *new_lin, char *delm);
int _exec(char **arry, char *lin, int index, char **name);
size_t _getline(char **linptr, size_t *n, FILE *stream);
void _comment(char *lin);
char *_strtok(char *string, char *delm);
char *handle_path(char *command, char *path);
char *_getpath(char *command, char *path);
char *get_full_path(char *cmd, char *path);

int check_built(char *cmd);
void handle_built(char **arry, int status,
		char *cmd, int index, char **argv, char **tokenizer);
char *_getenv(char *virn);


int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *str1, char *str2);
char *_strchr(char *str, char c);
char *_strdup(char *string);
int _strncmp(const char *s1, const char *s2, size_t numb);


int _isspace(char s);
int _isempty(const char *string);
int _atoin(char *str);
void _free(char *f, char **f1);


int _putchar(char p);
void _puts(char *string);


void print_error(char *name, char *cmd, int index);
char *_itoa(int m);
void rev_str(char *string, int length);
#endif
