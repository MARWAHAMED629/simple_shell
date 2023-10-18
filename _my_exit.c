#include "shell.h"

/**
 * _my_exit - exit from the shell
 * @command: Structure containing potential argument use it ,
 *          constant function prototype.
 *  Return: exit status
 *         (0) if command.argv[0] != "exit"
 */
int _my_exit(cmds_t *command)
{
	int chkexit;

	if (command->argv[1])
	{
		chkexit = error_atoi(command->argv[1]);
		if (chkexit == -1)
		{
			command->last_statue = 2;
			err_print (command, "Illegal number: ");
			_print_in(command->argv[1]);
			_print_char('\n');
			return (1);
		}
		command->error_v = error_atoi(command->argv[1]);
		return (-2);
	}
	command->error_v = -1;
	return (-2);
}
