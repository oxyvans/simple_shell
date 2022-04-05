#include "main.h"

/**
 *
 *
 */
char *_getenv(char* str)
{
	int x = 0, y = 0, j = 0, i = 0;
	char *environment, *path;
	environment = env();

	while (environment[x])
	{
		while (str[j] != '\0' && str[j] == environment[x][y])
		{
			y++;
			j++;
		}
		if (str[j] == '\0')
			break;
	}
	y++;
	for (i = 0; environment[y] != '\n'; i++, y++)
	{
		path[i] = environment[y];
	}
	return(path);
}

/**
 *
 *
 */
char *findpath(char *str)
{
	char *string, **path, *tok, *buf;
	int i = 0, j = 0;
	string = _getenv("PATH");
	buf = malloc(sizeof(struct stat));
	tok = strtok(string, ":");
	for (i = 0; i < 25 && tok != NULL; i++)
	{
		path[i] = tok;
		tok = strtok(NULL, ":");
	}

	while (path[j] != NULL)
	{
		if (stat(str, buf) == 0) 
			break;
		j++;
	}

	return(path[i]);




}
