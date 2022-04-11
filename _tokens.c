#include "main.h"

/**
 * tokens - tokenaizer
 * @imput: line
 * Return: tokens
 */

char **tokens(char *imput)
{
	int i = 0;
	char **comm, *tok = NULL;

	comm = malloc(sizeof(char *) * 32);
	if (!comm)
	{
		free(comm);
		perror("MALLOC FAIL");
		exit(EXIT_FAILURE);
	}

	tok = strtok(imput, " \t\n\r");

	for (; tok != NULL; i++)
	{
		comm[i] = tok;
		tok = strtok(NULL, " \t\n\r");
	}

	comm[i] = NULL;
	return (comm);
}
