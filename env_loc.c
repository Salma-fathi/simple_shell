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
    int cmd_length, dir_length;
    struct stat buffer;

    path = getenv("PATH");

 if (path)
	{
    
        path_cpy = strdup(path);
        
        cmd_length = strlen(command);
        path_token = strtok(path_cpy, ":");

 while(path_token != NULL)
	{
         
            dir_length = strlen(path_token);
            
            file_path = malloc(cmd_length + dir_length + 2);
            strcpy(file_path, path_token);
            strcat(file_path, "/");
            strcat(file_path, command);
            strcat(file_path, "\0");

            
 if (stat(file_path, &buffer) == 0)
	   {
                free(path_cpy);
                return (file_path);
            }
 else
	{
               
                free(file_path);
                path_token = strtok(NULL, ":");

        }

        }

        free(path_cpy);
 if (stat(command, &buffer) == 0)
        {
            return (command);
        }
        return (NULL);
    }
    return (NULL);
}
