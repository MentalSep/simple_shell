#include "main.h"

/**
 * checkDelim - checks if a character is a delimiter
 * @c: character to be checked
 * @delim: delimiter
 * Return: 1 if true, 0 if false
 */
int checkDelim(char c, char *delim)
{
	int i = 0;

	for (; delim[i]; i++)
	{
		if (c == delim[i])
			return (1);
	}
	return (0);
}
/**
 * _strtok - function that splits a string into tokens.
 * @str: string to be splitted
 * @delim: delimiter
 * Return: pointer to the next token
 */
char *_strtok(char *str, char *delim)
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
		if (!checkDelim(*next, delim))
			break;
	}
	if (*next == '#' || *next == '\0' || *next == '\n')
		return (NULL);

	while (*next != '\0')
	{
		if (checkDelim(*next, delim))
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
