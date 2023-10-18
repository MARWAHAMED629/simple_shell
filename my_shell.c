#include "shell.h"

/**
 * run_myshell - main shell loop
 * @command: the parameter of  struct
 * @av: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int run_myshell(cmds_t *command, char **av)
{
	ssize_t sucsess = 0;
	int v_return = 0;

	while (sucsess != -1 && v_return  != -2)
	{
		clear_cmd(command);
		if (interactive(command))
			_puts("$ ");
		_print_char(BUF_FLUSH);
		sucsess = input_user(command);
		if (sucsess != -1)
		{
			Initializing_cmd(command, av);
			v_return = found_built(command);
			if (v_return == -1)
				found_cmds(command);
		}
		else if (interactive(command))
			my_putchar('\n');
		frees_cmds(command, 0);
	}
	w_history(command);
	frees_cmds(command, 1);
	if (!interactive(command) && command->last_statue)
		exit(command->last_statue);
	if (v_return  == -2)
	{
		if (command->error_v == -1)
			exit(command->last_statue);
		exit(command->error_v);
	}
	return (v_return);
}

