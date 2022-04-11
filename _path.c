#include "main.h"

/**
 * _getenv - main
 * @env: environment
 * Return: path
 */

char *_getenv(char **env)
{
	char *_path = "PATH";
	char *p;
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
 * @command: commands
 * Return: tokens
 */

char *_tokens_path(char *command)
{
	char *tok, *direct = NULL, *path, *tmp = NULL;
	struct stat status;

	path = _getenv(environ);

	tok = strtok(path, ":");

	if (command[0] == '/')
	{
		free(path);
		return ("is_path");
	}

	do {
		if (_strcmp(command, "./") == 0)
			return("is_dir");
		tmp = tok;
	
		tmp = str_concat(tmp, "/");
		
		direct = str_concat(tmp, command);
		free(tmp);

		if (stat(direct, &status) == 0)
		{
			free(path);
			return (direct);
		}

		tok = strtok(NULL, ":");
		free(direct);
	} while (tok != NULL);

	free(path);
	return ("no_command");
}
