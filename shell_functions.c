#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode.
 * @cmd: struct addresses
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(cmds_t *cmd)
{
	return (isatty(STDIN_FILENO) && cmd->readfiledes <= 2);
}

/**
 * _delimeter - it  checks if character is a delimeter
 * @n:  char to check
 * @d: it is a delimeter string
 * Return: 1 if true, 0 if false
 */
int _delimeter(char n, char *d)
{
	while (*d)
		if (*d++ == n)
			return (1);
	return (0);
}

/**
 * my_alpha - it checks for alphabet character
 *@n:  it is a character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int my_alpha(int n)
{
	if ((n >= 'a' && n <= 'z') || (n >= 'A' && n <= 'Z'))
		return (1);
	else
		return (0);
}

