<div><img src = "https://user-images.githubusercontent.com/81387977/155136726-0acad71c-42d2-41f0-ad62-784d315048b8.png"></div>

## Description

hsh is a simple UNIX command interpreter that reads commands from standard input and executes them, simulating the behavior of the sh (/bin/sh) command interpreter (shell).


### Compilation

The code compile with `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh` command.

|IMPLEMENTATION                                                         |EXAMPLE                                     |
|-----------------------------------------------------------------------|--------------------------------------------|
| Handles simple commands                                               |`/bin/ls`		                     |
| Handles the `PATH`                                                    |`ls`, `pwd`	                             |
| Handles command lines with arguments                                  |`/bin/ls -las`, `ls -la /home`		     |
| Handles the `Ctrl + D`					        |                                            |
| Handles the `Ctrl + C` 				                |                                            |
| Handles `help` command that prints information about builtin commands | `help help`,		                     |
| Handles `exit` command that exits the shell                           | `exit`                                     |
| Handles `env`  command that prints the current environment            | `env`                                      |
| Handles `cd`   command to change directory                            | `cd /home`                                 |


## Examples

## interactive mode
```
root@holberton:/home/simpleshell ./hsh
$ ls\n
README.md  shell.c  _signal.c  str2.c  str.c  _tokens.c
$ 
```
## non-interactive mode
```
root@holberton:/home/simpleshell echo "ls" | ./hsh
README.md  shell.c  _signal.c  str2.c  str.c  _tokens.c
root@holberton:/home/simpleshell#
```
## Authors

Benjamín Gutiérrez and Nicolle Shiskobcki.
