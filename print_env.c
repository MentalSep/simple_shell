#include "main.h"

/**
 * _strchr - locates a character in a string.
 *
 * @s: string to check.
 * @c: character to locate.
 *
 * Return: pointer to s, otherwise NULL if character is not found.
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i]; i++)
		if (s[i] == c)
			return (&s[i]);
	/* in case c is '\0'*/
	if (s[i] == c)
		return (&s[i]);
	return (0);
}

/**
 * print_env - prints the environment
 * Return: void
 */
void print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		if (_strchr(environ[i], '='))
		{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		}
		i++;
	}
}
