#include "main.h"

/**
 * _exe - execute.
 * @command:argumen count.
 * Return: status.
 */

int _exe(char **command)
{
	struct stat s;
	int status = 1;
	pid_t child;
	char *exec;

	exec = _tokens_path(command[0]);

	if (_strcmp(exec, "no_command") == 0)
		printf("./hsh: 1: %s: not found\n", command[0]);

	if (_strcmp(exec, "is_path") != 0)
		command[0] = exec;
	
	if (_strcmp(exec, "is_dir") == 0)
		printf("./hsh: %s: Is a directory\n", command[0]);

	if (stat(command[0], &s) == 0)
	{
		child = fork();

		if (child == 0)
		{
			status = execve(command[0], command, environ);
			if (status == -1)
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
