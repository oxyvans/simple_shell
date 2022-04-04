#include "main.h"

/**
 * _check - checks for exit or env
 * @param: input from getline
 */
void _check(char *param)
{
	if (_strcmp(param, "exit") == 0)
		exitshell();
	else
	if (_strcmp(param, "env") == 0)
	       	get_env();

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
	for (i = 0; environ[i] != '\0', i++)
		printf("%s\n", environ[i]);
	return (0);
}
