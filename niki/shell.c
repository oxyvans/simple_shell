#include "main.h"

/**
 * main - execute the shell.
 * @argc:argumen count.
 * @argv:argument vector.
 * @env: environment.
 * Return: always 0.
 */

int main()
{
	int status = 1, mod = 0, flag = 1;
	char *imput = NULL, **command = NULL;
	pid_t child;
	
	mod = isatty(STDIN_FILENO);
	while (1)
	{
		if (mod == 1)
			printf("$ ");
		
		signal(SIGINT, ignore_cc);

		imput = _getline();
	
		command = tokens(imput);
			
	/*-------------mejorar---------------*/
	
		flag = _check(command[0]);
		
		if (flag == 0)
		{
			free(command);
			free(imput);
			exitshell();
		}

		if (flag != 3)
		{
			command[0] = _tokens_path(command[0]);
			child = fork();

			if (child == 0)
			{
				if (execve(command[0], command, NULL) == -1)
				{
					free(command); /**/
					free(imput);
					perror("Bash");
					exit(1);
				}
			}

			if (child > 0)
				wait(&status);
			free(command[0]); /**/
		}
		 if (imput)
			free(imput);
		 free(command);
	}
	free(command);
	return (0);
}
