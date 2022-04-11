#include "main.h"

/**
 * main - execute the shell.
 * @argc:argumen count.
 * @argv:argument vector.
 * @env: environment.
 * Return: always 0.
 */

int main(int argc, char *argv[], char **env)
{
	int mod = 0, flag = 0;
	char *imput = NULL, **command = NULL;

	(void)argc;
	(void)env;

	mod = isatty(STDIN_FILENO);
	while (1)
	{
		if (mod == 1)
			printf("$ ");

		signal(SIGINT, ignore_cc);

		imput = _getline();

		command = tokens(imput);

		flag = _check(command, argv);
		
		if (imput)
			free(imput);

		free(command);

		if (flag == 1)
			return (0);

		if (mod == 0)
			return (flag);
	}

	return (flag);
}
