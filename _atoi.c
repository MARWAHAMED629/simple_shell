#include "shell.h"
/**
 * _atoi -Used to convert a text string to an integer.
 * @my_str:array of char  should convert to integer.
 * Return: converted string
 **/
int _atoi(char *my_str)
{
	int x, sign = 1, f = 0, o;
	unsigned int r = 0;

	for (x = 0; my_str[x] != '\0' && f != 2; x++)
	{
		if (my_str[x] == '-')
			sign *= -1;

		if (my_str[x] >= '0' && my_str[x] <= '9')
		{
			r = 1;
			r *= 10;
			r += (my_str[x] - '0');
		}
		else if (f == 1)
			f = 2;
	}

	if (sign == -1)
		o = -r;
	else
		o = r;

	return (o);
}
