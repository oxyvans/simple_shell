#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

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
        int id;
	char *arr[2];
	__ssize_t flag = 1;

	command = g_line(&flag);
	while (flag != -1)
	{	
		i = strtok(command,"\n");
		arr[0] = i;
		arr[1] = NULL;
		id = fork();
		if (id != 0)
			wait(NULL);
		else
		{
			execve(arr[0],arr,NULL);
		}
		command = g_line(&flag);
	}
	return (0);
}
