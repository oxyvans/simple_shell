#include "main.h"

/**
 * main - execute the shell.
 * @argc:argumen count.
 * @argv:argument vector.
 * @env: environment.
 * Return: always 0.
 */

int main(int argc, char **argv, char **env)
{
	int status = 1, mod = 0, flag = 1, i = 0;
	char *imput = NULL, *command[16], *tok = NULL;
	pid_t child;

	(void)argc;
	(void)argv;
	(void)env;

	mod = isatty(STDIN_FILENO);

	while (1)
	{
		if (mod == 1)
			printf("$ ");

		signal(SIGINT, ignore_cc);

		imput = _getline();

	/*-------------mejorar---------------*/
	
		tok = strtok(imput, " \t\n\r");

		for (i = 0; i < 16 && tok != NULL; i++)
		{
			command[i] = tok;
			tok = strtok(NULL, " \t\n\r");
		}

		command[i] = NULL;
		flag = _check(command[0]);
		
		if (flag == 0)
		{
			free(imput);
			exitshell();
		}

		if (flag != 3)
		{
			child = fork();

			if (child == 0)
			{
				if (execve(command[0], command, NULL) == -1)
				{
					free(imput);
					perror("execve");
					exit(1);
				}
			}

			if (child > 0)
				wait(&status);
		}
		if (imput)
			free(imput);

	}
	return (0);
}
