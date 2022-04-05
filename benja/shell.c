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
	int status = 1, mod = 0;
	char *input = NULL, *command = NULL;

	(void)argc;
	(void)argv;

	mod = isatty(STDIN_FILENO);

	while (status)
	{
		if (mod != 1)
			status = 0;
		else
			printf("$ ");

		signal(SIGINT, SIG_IGN);
		line = _getline();
	}
}
