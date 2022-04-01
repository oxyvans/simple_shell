#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* g_line(__ssize_t *flag)
{
    char *buffer;
    size_t bufsize = 32;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }

    printf("$ ");
   *flag = getline(&buffer,&bufsize,stdin);
    

    return(buffer);
}

int main()
{
	char *command;
	char *i; 
	__ssize_t flag = 1;

	command = g_line(&flag);
	while (flag != -1)
	{	
		i = strtok(command," ");
		while (i) 
		{
			printf("%s\n",i);
			i = strtok(NULL, " ");
		}
	command = g_line(&flag);
	}
	return (0);
}
