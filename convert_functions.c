#include "shell.h"
/**
 *my_print_cust - function prints a decimal (integer) number (base 10)
 * @in: it an input
 * @filedes: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int my_print_cust(int in, int filedes)
{
	int (*_putchar)(char) = my_putchar;
	int z, c = 0;
	unsigned int _absolut, curr;

	if (filedes == STDERR_FILENO)
		_putchar = _print_char;
	if (in < 0)
	{
		_absolut = -in;
		_putchar('-');
		c++;
	}
	else
		_absolut = in;
	curr = _absolut;
	for (z = 1000000000; z > 1; z /= 10)
	{
		if (_absolut / z)
		{
			_putchar('0' + curr / z);
			c++;
		}
		curr %= z;
	}
	_putchar('0' + curr);
	c++;

	return (c);
}


/**
 * conv_num - converter function.
 * @num: number
 * @b: the base
 * @f: argument flags
 *
 * Return: string
 */
char *conv_num(long int num, int b, int f)
{
	static char *a;
	static char buffer[50];
	char sign = 0;
	char *p;
	unsigned long n = num;

	if (!(f & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	a = f & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buffer[49];
	*p = '\0';

	do	{
		*--p = a[n % b];
		n /= b;
	} while (n != 0);

	if (sign)
		*--p = sign;
	return (p);
}



