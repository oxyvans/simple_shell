#ifndef SHELL_H
#define SHELL_H

extern char **environ;

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>

/*---shell-funcion---*/
int main(int argc, char *argv[], char **env);
char *_getline(void);
int _check(char **command);
int env(void);
void ignore_cc(int n);
char *_getenv(char **env);
char **tokens(char *imput);
char *_tokens_path(char *command);
int _exe(char **command);
int help(void);
int _cd(char **command);

/*---str-funcion---*/
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int aux_getenv(char *s1, char *s2);
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
char *_strcat(char *dest, char *src);

#endif
