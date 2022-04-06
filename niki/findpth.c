#include "main.h"
extern char **environ;

/**
 *
 *
 */
char *_getenv(char* word)
{
	int x = 0, y = 0, i = 0;
	char *flag;
	char *str[300];
	while (environ)
	{
		flag = _strstr(environ[y], word);
		if (flag == NULL)
			y++;
		if (flag != NULL)
			break;
	}
	for (x = 7; environ[x][y] != '\n'; x++)
	{
		str[i] = environ[x][y];
		i++;
	}
	return (str);
}

/**
 *
 *
 */
char *findpath(char *str)
{
	char *string;
	string = _getenv("PATH");

	

}
