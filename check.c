#include "main.h"

/**
 * _check - checks
 * @command: input from getline
 * Return: status
 */

int _check(char **command, char **argv)
{
	if (command[0] == NULL)
		return (1);

	if (_strcmp(command[0], "exit") == 0)
		return (0);

	if (_strcmp(command[0], "env") == 0)
		return (env());

	if (_strcmp(command[0], "help") == 0)
		return (help());

	if (_strcmp(command[0], "cd") == 0)
		return (_cd(command));

	return (_exe(command, argv));
}

/**
 * _cd - chdir
 * @command: command
 * Return: status
 */

int _cd(char **command)
{

	if (command[1] == NULL)
		command[1] = "/home/";

	chdir(command[1]);

	return (1);
}

/**
 * env - prints env
 * Return: status
 */

int env(void)
{
	int i = 0;

	for (i = 0; environ[i] != NULL; i++)
		printf("%s\n", environ[i]);

	return (1);
}

/**
* help - prints help
* Return: status
*/

int help(void)
{
	printf("Simple Shell by Benjamín Gutierrez and Nicolle Shiskobcki\nTo exit type \"exit\"\nTo get environment type \"env\"\nFor more help search shell man on the internet\nHolberton School 2022\n ");

	return (1);
}
