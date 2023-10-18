#include "shell.h"

/**
 * my_setenv - set up a new environmental variable or modify an existing
 * @command: Structure cmds.
 *  Return: Always 0
 */
int my_setenv(cmds_t *command)
{
	if (command->argcount != 3)
	{
		_print_in("Incorrect number of arguements\n");
		return (1);
	}
	if (_mysetenv(command, command->argv[1], command->argv[2]))
		return (0);
	return (1);
}

/**
 * my_unsetenv - To remove an environmental variable from the system.
 * @command: Structure containing potential arguments.
 * Return: Always 0
 */
int myun_setenv(cmds_t *command)
{
	int u;

	if (command->argcount == 1)
	{
		_print_in("Too few arguements.\n");
		return (1);
	}
	for (u = 1; u <= command->argcount; u++)
		_myunsetenv(command, command->argv[u]);

	return (0);
}

