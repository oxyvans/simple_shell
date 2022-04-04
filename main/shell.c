#include <main.h>

/**
 * main - execute the shell.
 * @ac:argumen count.
 * @av:argument vector.
 * @env: environment.
 * Return: always 0.
 */

int main(__attribute__((unused)) int argc, char *argv[], char *env)
{
	pid_t child;
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

	child = fork();
	if (child == 0)
	{
		if (execve(command[0], command, NULL))
		{
			perror("execve");
			exit(1);
		}
	}
	if (child > 0)
 	wait(&status);
	}
	putchar('\n');  
	free(lineptr);
	exit(status);
}
