#include "main.h"
/**
 * main - Entry point
 * Description: c programm
 * @argv: vector of strings
 * @ac: count of vector 
 * Return: nothings
 */

int main(int ac, char **argv)
{
    char *prompt = " $ ";
    char *linptr = 0, *linptr_cpy = 0;
    size_t n = 0;
    ssize_t ch_read;
    const char *delim = " \n\t\a";
    int number_of_tokens = 0;
    char *token;
    int j;
    (void)ac;

while (1)
    {
	if(isatty(STDIN_FILEND))
		write(STDOUT_FILEND," $" , 2);

        ch_read = getline(&linptr, &n, stdin);
        if (ch_read == -1)
        {
            printf("Exiting\n");
            return (-1);
        }

        
        linptr_cpy = malloc(sizeof(char) * ch_read);
        if (linptr_cpy == NULL)
        {
            perror("MEMORY ALLOCATION ERROR");
            return (-1);
        }
        _strcpy(linptr_cpy, linptr);      
        token = strtok(linptr, delim);

        while (token != NULL)
        {
            number_of_tokens++;
            token = strtok(NULL, delim);
        }
        number_of_tokens++;
        argv = malloc(sizeof(char *) * number_of_tokens);
       
        token = strtok(linptr_cpy, delim);

        for (j = 0; token != NULL; j++)
        {
            argv[j] = malloc(sizeof(char) * (*_strlen(token)));
            _strcpy(argv[j], token);

            token = strtok(NULL, delim);
        }
        argv[j] = NULL;
        execute_command(argv);
    }

    
    free(linptr_cpy);
    free(linptr);

    return (0);
main.c}
