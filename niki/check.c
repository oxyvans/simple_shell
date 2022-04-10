#include "main.h"

/* _check - checks for exit or env
 * @param: input from getline
 */

int _check(char **command)
{
	if (command[0] == NULL)
		return (1);

	if (_strcmp(command[0], "exit") == 0)
		return (0);

	if (_strcmp(command[0], "env") == 0)
	       	return (env());

	if (_strcmp(command[0], "help") == 0)
		return (help());

	return (_exe(command));
}

/**
 * env: prints env
 * Return: 1
 */

int env()
{
	int i = 0;

	for (i = 0; environ[i] != NULL; i++)
		printf("%s\n", environ[i]);

	return(1);
}

/**
* help - prints help
* Return: 1
*/
int help()
{
	printf("Simple Shell by Benjamín Gutierrez and Nicolle Shiskobcki\nTo exit type \"exit\"\nTo get environment type \"env\" \nFor more help search shell man on the internet \nHolberton School 2022\n ");
	return(1);
}
