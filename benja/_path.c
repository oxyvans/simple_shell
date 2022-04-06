#include "main.h"

/**
 * _getenv - main
 * @env: environment
 * Return: path
 */

char *_getenv(char **env)
{
	char *_path = "PATH";
	int x = 0, y = 0;

	for (x = 0; env[x] != NULL; x++)
	{

		for (y = 0; env[x][y] != '='; y++)
		{
			if (aux_getenv(_path, env[x]) == 0)
			{	
				return (env[x]);
			}
			break;
		}
	}
	return (env[x]);
}
