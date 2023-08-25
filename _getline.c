#include "main.h"
/**
 * _getline - Reads a line from a file
 * @lineptr: where the line will be stored
 * @n: stores the buff size
 * @stream: FILE object
 * Return: number of characters in a line, or -1 on error
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t rBytes;
	ssize_t line_len;
	char c = 'a', *buff;
	int rValue;

	if (rBytes == 0)
		fflush(stream);
	buff = malloc(sizeof(char) * 10024);
	if (!buff)
		return (-1);
	while (c != '\n')
	{
		rValue = read(STDIN_FILENO, &c, 1);
		if (rValue == -1 || (rValue == 0 && rBytes == 0))
		{
			free(buff);
			return (-1);
		}
		if (rValue == 0 && rBytes != 0)
		{
			rBytes++;
			break;
		}
		if (rBytes >= 10023)
			buff = realloc(buff, rBytes + 1);

		buff[rBytes] = c;
		rBytes++;
	}
	buff[rBytes] = '\0';
	*lineptr = buff;
	*n = rBytes;
	line_len = rBytes;
	if (rValue != 0)
		rBytes = 0;
	return (line_len);
}
