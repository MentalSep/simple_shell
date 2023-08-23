#include "main.h"

/**
 * prompt - prints a prompt
 * Return: pointer to the prompt
 */
char *prompt(void)
{
	size_t n = 0;
	char *line = NULL;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "($) ", 4);
	if (getline(&line, &n, stdin) == -1)
		return (NULL);
	line[_strlen(line)] = '\0';
	return (line);
}

/**
 * checkBuiltin - checks if the command is a builtin
 * @tokens: array of tokens
 * @line: command line
 * Return: 0 if builtin, 1 if not
 */
int checkBuiltin(char **tokens, char *line)
{
	if (_strcmp(tokens[0], "exit") == 0)
	{
		free(line);
		free(tokens);
		exit(0);
	}
	else if (_strcmp(tokens[0], "env") == 0)
	{
		print_env();
		return (2);
	}
	else if (_strcmp(tokens[0], "cd") == 0)
	{
		if (tokens[1] == NULL)
			chdir(getenv("HOME"));
		else
			chdir(tokens[1]);
		return (2);
	}
	return (1);
}

/**
 * execute - executes a command
 * @tokens: array of tokens
 * @cmd: name of the shell
 * @line_count: line count
 * Return: void
 */
int execute(char **tokens, char *cmd, int line_count)
{
	pid_t pid;
	int status;
	char *path = NULL;

	if (tokens[0][0] != '/' && tokens[0][0] != '.')
		path = getPath(tokens[0]);
	else
		path = tokens[0];
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, tokens, environ) == -1)
			print_error(cmd, line_count, tokens[0]);
	}
	else if (pid < 0)
		print_error(cmd, line_count, tokens[0]);
	else
		wait(&status);
	if (tokens[0][0] != '/' && tokens[0][0] != '.')
		free(path);
	return (status);
}

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0
 */
int main(__attribute__((unused))int argc, char **argv)
{
	int line_count = 0, status = 0;
	char *line = NULL;
	char **tokens = NULL;

	while (1)
	{
		line = prompt();
		if (line == NULL)
			break;
		line_count++;
		if (line[0] == '\n')
		{
			free(line);
			line = NULL;
			continue;
		}
		tokens = getArgs(line, " \t");
		if (tokens == NULL || *tokens == NULL)
		{
			free(line);
			line = NULL;
			continue;
		}
		if (checkBuiltin(tokens, line) == 2)
			continue;
		if (access(tokens[0], X_OK) != 1)
		{
			status = execute(tokens, argv[0], line_count);
			free(line);
		}
		else
			print_error(argv[0], line_count, tokens[0]), status = -1;
		free(tokens);
	}
	free(line);
	if (status)
		return (127);
	else
		return (0);
}
