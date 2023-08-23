#include "main.h"

/**
 * _strtok - function that splits a string into tokens.
 * @str: string to be splitted
 * @delim: delimiter
 * Return: pointer to the next token
 */
char *_strtow(char *str, char *delim)
{
	static char *token;
	static char *next;
	int i = 0;

	if (str != NULL)
		next = str;
	token = next;
	if (token == NULL)
		return (NULL);

	for (; *next; next++)
	{
		if (*next != *delim)
			break;
	}
	if (*next == '#')
		return (NULL);

	while (*next != '\0')
	{
		if (*next == *delim)
		{
			next++;
			break;
		}
		token[i] = *next;
		next++;
		i++;
	}
	token[i] = '\0';
	if (!token[0])
		return (NULL);

	return (token);
}
