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
	char *tok, *direct, *path;
	struct stat status;
	int i = 0;

	path = _getenv(environ);

	tok = strtok(path, ":");
	
	if (command[0] == '/')
	{	
		free(path);
		return (command);
	}

	do
	{
			direct = _strdup(tok);
			direct = str_concat(direct, "/");
			direct = str_concat(direct,command);

			if (stat(direct, &status) == 0)
			{
				free(path);
				return (direct);
			}
			else
				i++;
			
			tok = strtok(NULL, ":");
			free(direct);

	} while(tok != NULL);

	free(path);
	return(command);
}
