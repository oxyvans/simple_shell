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


char* mystrtok(char* s, char d)
{
	char* input = NULL, result;

	if (s != NULL)
        	input = s;
	
	if (input == NULL)
        	return NULL;

	result = malloc(sizeof(char) * (strlen(s) + 1));
}

int main()
{
	char *command = get_line();
	mystrtok(command," ");

	return (0);
}
