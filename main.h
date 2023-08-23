#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;

void print_env(void);
int _strlen(char *s);
char *_strtok(char *str, char *delim);
char **getArgs(char *line, char *delim);
int _strcmp(char *s1, char *s2);
void print_error(char *argv, int count, char *line);
char *getPath(char *bin);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);

#endif
