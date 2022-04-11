#include "main.h"

/**
 * _exe - execute.
 * @command:argumen count.
 * Return: status.
 */

int _exe(char **command, char **argv)
{
	struct stat s;
	int status;
	pid_t child;
	char *exec;

	exec = _tokens_path(command[0]);

	if (_strcmp(exec, "no_command") == 0)
		printf("%s: 1: %s: not found\n", argv[0], command[0]);
	
	if (_strcmp(exec, "is_ex") == 0)
		printf("%s: %s: Is a directory\n", argv[0], command[0]);

	if (_strcmp(exec, "is_path") != 0)
		command[0] = exec;

	if (stat(command[0], &s) == 0)
	{
		child = fork();

		if (child == 0)
		{
			if (execve(command[0], command, environ) == -1)
			{
				perror("./hsh");
			}
		}

		if (child > 0)
			wait(&status);

		if (_strcmp(exec, "is_path") != 0)
			free(command[0]);
	}

	return (1);
}
