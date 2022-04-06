#ifndef SHELL_H
#define SHELL_H

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
int main();
char *prompt();
int _check(char *param);
int exitshell();
int env();
char *_getenv(char *str);
char *findpath(char *str);
/*---str-funcion---*/
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strstr(char *s1, char *s2);
int compare(const char *X, const char *Y);
#endif
