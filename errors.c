#include "main.h"

/**
 * write_integer_error - writes an integer to stderr
 * @number: integer to be written
 * Return: number of characters printed
 */
int write_integer_error(int number)
{
	int temp, characters_printed = 0;
	unsigned int c1;

	if (number < 0)
	{
		number = -number;
		write(2, "-", 1);
		characters_printed++;
	}
	c1 = number;
	if (c1 / 10)
	{
		characters_printed += write_integer_error(c1 / 10);
	}
	temp = (c1 % 10) + '0';
	return (characters_printed += write(2, &temp, 1));
}

/**
 * print_error - prints error message
 * @argv: argv[0] from main
 * @count: number of commands executed
 * @line: command line
 * Return: void
 */
void print_error(char *argv, int count, char *line)
{
	char *count_str = NULL;

	write(STDERR_FILENO, argv, _strlen(argv));
	write(STDERR_FILENO, ": ", 2);
	write_integer_error(count);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, line, _strlen(line));
	write(STDERR_FILENO, ": not found\n", 12);
	free(count_str);
}

