#include "main.h"

int wordCount(char *str, char *delim)
{
	int i = 0, count = 0;

	for (; str[i]; i++)
	{
		if (str[i] != *delim)
		{
			count++;
			for (; str[i] && str[i] != *delim; i++)
				;
			i--;
		}
	}
	return (count);
}

/**
 * getArgs - function that splits a string into tokens.
 * @line: string to be splitted
 * @delim: delimiter
 * Return: array of tokens
 */
char **getArgs(char *line, char *delim)
{
	char **args = NULL;
	char *token;
	int i = 0;

	args = malloc(sizeof(char *) * wordCount(line, delim) + 1);
	if (!args)
		return (NULL);

	token = _strtok(line, delim);
	for (; token; i++)
	{
		if (token[0] == '\n')
			break;
		args[i] = token;
		token = _strtok(NULL, delim);
	}
	if (i)
		if (args[i - 1][_strlen(args[i - 1]) - 1] == '\n')
			args[i - 1][_strlen(args[i - 1]) - 1] = '\0';
	args[i] = NULL;

	return (args);
}

/**
 * getPath - gets the path of a command
 * @bin: command
 * Return: path of command
 */
char *getPath(char *bin)
{
	char *path, *copy, *Pcopy, **arr;
	int i;

	path = getenv("PATH");
	if (!path)
		return (NULL);
	Pcopy = _strdup(path);
	arr = getArgs(Pcopy, ":");

	for (i = 0; arr[i]; i++)
	{
		copy = malloc(sizeof(char) * _strlen(arr[i]) + _strlen(bin) + 2);
		copy = _strcpy(copy, arr[i]);
		copy = _strcat(copy, "/");
		copy = _strcat(copy, bin);
		if (access(copy, X_OK) == 0)
		{
			free(Pcopy);
			return (copy);
		}
		free(copy);
	}
	free(arr);
	free(Pcopy);
	return (NULL);
}
