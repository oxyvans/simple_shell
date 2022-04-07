#include "main.h"

/**
 * str_len - returns the length of a string.
 * @s: string.
 * Return: Length of @s.
 */

int _strlen(char *s)
{
	int i = 0;
	int cont = 0;

	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		cont++;
		i++;
	}
	return (cont);
}

/**
 * aux_getenv - s1 its in s2
 * @s1 : chars
 * @s2 : chars
 * Return: comp
 */

int aux_getenv(char *s1, char *s2)
{
	while (*s1 != '\0')
	{
		if (*s1 != *s2)
			return (1);

		s1++;
		s2++;
	}

	return (0);
}

/**
 * _strcmp - comp two strings
 * @s1 : chars
 * @s2 : chars
 * Return: comp
 */

int _strcmp(char *s1, char *s2)
{
	int i, j;
	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
	{
		i++;
	}
	if ((s1[i] == '\0') && (s2[i] == '\0'))
	{
		return (0);
	}
	else
	{
		if (s1[i] != s2[i])
	{
		j = s1[i] - s2[i];
		return (j);
	}
	else
		return (0);
	}
}

/**
 * _strdup - main
 * @str : chars
 * Return: chars
 */

char *_strdup(char *str)
{
	char *res;
	int i;
	int size = 0;

	if (str == NULL)
		return (NULL);

	for (size = 0; str[size] != '\0'; size++)
	{
	}

	size++;
	res = malloc(size * sizeof(char));

	if (res == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		res[i] = str[i];
	}
	return (res);
}

/**
 * str_concat - main
 * @s2 : size
 * @s1 : char
 * Return: chars
 */
char *str_concat(char *s1, char *s2)
{
	char *res;
	int i, j, size1 = 0, size2 = 0;

	if (s1 == NULL && s2 == NULL)
	{
		res = malloc(1 * sizeof(char));
		res[0] = '\0';
		return (res);
	}
	if (s1 != NULL)
	{
	for (size1 = 0; s1[size1] != '\0'; size1++)
	{
	}
	}
	if (s2 != NULL)
	{
	for (size2 = 0; s2[size2] != '\0'; size2++)
	{
	}
	}
	res = malloc((size1 + size2 + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	for (i = 0; i < size1; i++)
	{
		res[i] = s1[i];
	}
	for (j = 0; j < size2; i++, j++)
	{
		res[i] = s2[j];
	}
	res[i] = '\0';
	return (res);
}
