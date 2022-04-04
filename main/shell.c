#include "main.h"

/**
 * main - execute the shell.
 * @ac:argumen count.
 * @av:argument vector.
 * @env: environment.
 * Return: always 0.
 */

int main()
{
	pid_t child;
	char *command[5];
	char *tok, *lineptr = NULL;
	size_t i;
	int status;

	while (1)
	{
		lineptr = prompt();

		tok = strtok(lineptr, " \t\n\r");
		for (i = 0; i < 16 && tok != NULL; i++)
		{
			command[i] = tok;
			tok = strtok(NULL, " \t\n\r");
		}

		command[i] = NULL;
		_check(command[0]);
		child = fork();

		if (child == 0)
		{
			if (execve(command[0], command, NULL) == -1)
			{
				free(lineptr);
				perror("execve");
				exit(1);
			}
		}

		if (child > 0)
			wait(&status);

	}
	putchar('\n');
	free(lineptr);
	free(tok);
	free(command);
	exit(status);
 }
