#include "main.h"

/* _check - checks for exit or env
 * @param: input from getline
 */

int _check(char *param)
{
	int flag = 1;
	if (_strcmp(param, "exit") == 0)
	{
		flag = 0;
	}
	else
	if (_strcmp(param, "env") == 0)
	{
	       	flag = env();
	}
return (flag);
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
	return(3);
}
