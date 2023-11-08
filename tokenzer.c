#include
char **tokenzer;(char *Line)
{
    char *token;
    char **command NULL ;
    int count = 0, *tmp =NULL;
    

    if(!Line)
        return(NULL);
    tmp = _strdup(Line);

    token = _strtok(tmp , ARR);
    if(token)
    {
        free(Line) ,Line = NULL;
        free(tmp), tmp = NULL;
        return(NULL);
    }
    while(token)
    {
        count++;
        token = _strtok(NULL , ARR);

    }
    free(tmp), tmp =NULL;
    
    if(!command)
    {
        free(Line);
        return(NULL);
    }
    
    token = _strtok(Line , ARR);
    while(token)
    {
        command[i++] = token;
        token = _strtok(NULL , ARR);
        i++;

    }
    free(Line),Line =NULL;
    command[i] = NULL;
    return(command);
}
