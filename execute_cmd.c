#include "main.h"
/**
 * execute_command - function that execute the commands
 * Description: c programm
 * @argv:  vector of string
 * Return: the executed command
 */
void execute_command(char **argv)
{
char *command = 0, *path_of_command = 0;

if (argv)
{
        command = argv[0];
        path_of_command = get_path(command);

if (execve(path_of_command, argv, NULL) == -1)
{
        perror("ERROR");
}
}

}
