#include "shell.h"
/**
 *_pfiled - it is a prints an input string.
 * @string: it to be printed
 * @filedes: the filedescription to write.
 *
 * Return: the number of charcter.
 */
int _pfiled(char *string, int filedes)
{
	int c = 0;

	if (!string)
		return (0);
	while (*string)
	{
		c += _printfile_d(*string++, filedes);
	}
	return (c);
}

/**
 * _print_char - it  write a character n to stderr
 * @n: it is a character it will print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _print_char(char n)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (n == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(2, buf, x);
		x = 0;
	}
	if (n != BUF_FLUSH)
		buf[x++] = n;
	return (1);
}

/**
 *_printfile_d - it write a character a to give file description.
 * @a: it a character to prints
 * @fdescription: a filedescription to write .
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _printfile_d(char a, int fdescription)
{
	static int f;
	static char buf[WRITE_BUF_SIZE];

	if (a == BUF_FLUSH || f >= WRITE_BUF_SIZE)
	{
		write(fdescription, buf, f);
		f = 0;
	}
	if (a != BUF_FLUSH)
		buf[f++] = a;
	return (1);
}

/**
 *_print_in - it  prints an input string.
 * @s: the string it will printed.
 *
 * Return: Nothing
 */
void _print_in(char *s)
{
	int c = 0;

	if (!s)
		return;
	while (s[c] != '\0')
	{
		_print_char(s[c]);
		c++;
	}
}

