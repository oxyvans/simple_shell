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
int main(__attribute__((unused)) int argc, char *argv[], char *env);

/*---str-funcion---*/
int _strlen(char *s);
int _strcmp(char *s1, char *s2);

#endif
