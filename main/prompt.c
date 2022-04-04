#include "main.h"

/**
 * prompt - prints $ and gets the line from input
 * Return: returns in buffer the line
 */
char *prompt()
{
char *buffer;
size_t bufsize = 16;
int l, status;
	
	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit (1);
	}

	printf("$ ");
	status = getline(&buffer, &l, stdin);
	if (status == -1)
	{
		free(buffer);
		exit(-1);
	}
	return (buffer);
}
