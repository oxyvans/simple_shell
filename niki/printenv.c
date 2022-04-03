#include "main.h"

/**
 * pt_char - our own putchar?
 * Return: prints char
 */
int pt_char(char x)
{
	return (write(1, &c, 1));
}

/**
 * _printenv - prints env variables
 * @env: current environment 
 */
void _printenv(char **env)
{
int a = 0;
int b = 0;
	while (env[a] != '\0')
	{
		a++;
		while (env[a][b] != '\0')
		{
			b++;
			pt_char(env[a][b]);
		}
	pt_char('\n');	
	}
}

