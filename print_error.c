#include "shell.h"
/**
 * err_print - print  error message
 * @cmds:  parameter & return command struct
 * @e: error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void err_print(cmds_t *cmds, char *e)
{
	_puts(cmds->filesn);
	_puts(": ");
	my_print_cust(cmds->line_c, STDERR_FILENO);
	_puts(": ");
	_puts(cmds->argv[0]);
	_puts(": ");
	_puts(e);
}



/**
 * error_atoi - convert string to int
 * @b:  string will be convert.
 * Return: 0 if no number in string, converte number otherwise
 *       -1 on error
 */
int error_atoi(char *b)
{
	int z = 0;
	unsigned long int r = 0;

	if (*b == '+')
		b++;
	for (z = 0;  b[z] != '\0'; z++)
	{
		if (b[z] >= '0' && b[z] <= '9')
		{
			r *= 10;
			r += (b[z] - '0');
			if (r > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (r);
}

