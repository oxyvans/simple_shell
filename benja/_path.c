#include "main.h"

/**
 * _getenv - main
 * @env: environment
 * Return: path
 */

char *_getenv(char **env)
{
	char *_path = "PATH";
	char * p;
	int x = 0, y = 0;

	for (x = 0; env[x] != NULL; x++)
	{

		for (y = 0; env[x][y] != '='; y++)
		{
			if (aux_getenv(_path, env[x]) == 0)
			{
				p = _strdup(env[x]);	
				return (p);
			}
			break;
		}
	}
	return (env[x]);
}

/**
 * _tokens_path - main
 * @path: path
 * Return: tokens
 */

char *_tokens_path(char *command)
{
	char *tok, *direct[10], *path;
	struct stat status;
	int i = 0;

	path = _getenv(environ);

	tok = strtok(path, ":");
	
	if (command[0] == '/')
	{
		return (command);
	}

	do
	{
			direct[i] = NULL;
			direct[i] = _strdup(tok);
			direct[i] = str_concat(direct[i], "/");
			direct[i] = str_concat(direct[i],command);

			if (stat(direct[i], &status) == 0)
			{
				return (direct[i]);
			}
			else
				i++;

		tok = strtok(NULL, ":");
	} while(tok != NULL);
	free(path);
	return(command);
}
