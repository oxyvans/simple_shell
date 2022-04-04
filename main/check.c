#include "main.h"
extern char **environ;

/* _check - checks for exit or env
 * @param: input from getline
 */

void _check(char *param)
{
	if (_strcmp(param, "exit") == 0)
	{
		exitshell();
	}
	else
	if (_strcmp(param, "env") == 0)
	{
	       	env();
	}

}

/**
 * exitshell - exits shell
 * Return: success
 */

int exitshell()
{
	exit(EXIT_SUCCESS);
}

/**
 * env: prints env
 * Return: 0
 */

int env()
{
	int i = 0;	
	for (i = 0; environ[i] != NULL; i++)
		printf("%s\n", environ[i]);
	return (0);
}
