#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_line()
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
    getline(&buffer,&bufsize,stdin);
    

    return(buffer);
}

int main()
{
	char *command = get_line();
	char *i = strtok(command, " ");
	
	while (i) 
	{
		printf("%s\n", i);
		i = strtok(NULL, " ");
	}
	return (0);
}
