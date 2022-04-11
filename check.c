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
		return (help(command[1]));

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

int help(char* command)
{
	if (command == NULL)
	{
		printf("Help works for\nexit\npwd\ncd\n");
		return(1);
	}
	if (_strcmp(command, "exit") == 0)
	{
		printf("Help Exit\nType \"exit\" to exit the terminal\n");
		return (1);
	}
	if (_strcmp(command, "pwd") == 0)
	{
		printf("Help PWD\nType \"pwd\" to see previous working directory\n");
		return (1);
	}
	if (_strcmp(command, "cd") == 0)
	{
		printf("Help cd\nType \"cd\" to change directory\n");
		return (1);
	}


	return (1);
}
