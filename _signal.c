#include "main.h"

/**
 * ignore_cc - ignore Ctrl-C input
 * @n: takes in int from signal
 *
 */

void ignore_cc(int n)
{
	(void)n;
	write(STDOUT_FILENO, "\n$ ", 3);
}
