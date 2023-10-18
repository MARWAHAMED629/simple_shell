#include "shell.h"
/**
 * _help_print - change  current directory of the process
 * @command: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _help_print(cmds_t *command)
{
	char **arg_array;

	arg_array = command->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
