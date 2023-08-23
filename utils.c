#include "main.h"

/**
 * _strlen - calculates length of a string
 * @s: string
 * Return: length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: difference between strings
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break;
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 * _strdup - eturns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 *
 * @str: pointer to string.
 *
 * Return:  returns a pointer to the duplicated string. It
 * returns NULL if insufficient memory was available
 */
char *_strdup(char *str)
{
	int i;
	char *dup;

	if (!str)
		return (NULL);
	for (i = 0; str[i]; i++)
		;
	dup = malloc(sizeof(*dup) * (i + 1));
	if (!dup)
		return (NULL);
	for (i = 0; str[i]; i++)
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}

/**
 * _strcat - concatenates two strings.
 *
 * @dest: destination string.
 * @src: source string.
 *
 * Return: pointer to dest.
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j;

	while (dest[i])
		i++;
	for (j = 0; src[j]; i++, j++)
		dest[i] = src[j];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcpy - copies the string pointed by src, to the buffer pointed by dest
 *
 * @src: the source of the copy
 * @dest: the destination of the copy
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
