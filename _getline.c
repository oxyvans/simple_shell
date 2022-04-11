
#include "main.h"

/**
 * _getline - gets the line from input
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
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
	}
	return (buffer);
}
