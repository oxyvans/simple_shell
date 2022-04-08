#include "main.h"

/**
 * prompt - gets the line from input
 * Return: returns in buffer the line
 */

char *_getline()
{
	char *buffer = NULL;
	size_t l = 0;
	int status;

	status = getline(&buffer, &l, stdin);

	if (status == -1)
	{
		free(buffer);
		exit(EXIT_FAILURE);
	}
	return (buffer);
}
