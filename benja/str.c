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
