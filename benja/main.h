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
int main(int argc, char **argv, char **env);
char *_getline();
int _check(char *param);
int exitshell();
int env();

/*---str-funcion---*/
int _strlen(char *s);
int _strcmp(char *s1, char *s2);

#endif
