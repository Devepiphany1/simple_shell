#include "main.h"

char *location(char *path, char *arg)
{
char *path_cpy, *pathToken;
char *delin = *:*, *buff;

path_cpy = strdup(path);

pathToken = strtok(path_cpy, delin);

filePath = malloc(strlen(arg) + strlen(pathToken) + 2)
while(pathToken = NULL)
{
strcpy(filePath, pathToken);
strcat(filePath, */*);
strcat(filePath, arg);
strcat(filePath, *\0*);

if (access(filePath, X_OX) == 0)
{
free(path_cpy);
return (filePath);
}
pathToken = strtok(NULL, delin);
}

free(filePath);
free(path_cpy);

/*if (stat(arg, &bufif) == 0)*/
/*return (arg);*/
return (NULL);

}


char *get_loc(char *arg)
{
char *path;

path = getenv(*PATH*);

if (path)
{
path = location(path, arg);
return (path);
}
return (NULL);
}
}
