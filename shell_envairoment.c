#include "shell.h"


/**
 * _get_myenv - gets the value of an environ variable
 * @command: Structure containing potential arguments. Used to maintain
 * @n: envairoment variables name.
 *
 * Return: value
 */
char *_get_myenv(cmds_t *command, const char *n)
{
	lists_t *nd = command->env;
	char *z;

	while (nd)
	{
		z = _start_with(nd->s, n);
		if (z && *z)
			return (z);
		nd = nd->next;
	}
	return (NULL);
}



/**
 * my_env - it is a prints of the  current environmental
 * @command: Structure containing arg.
 *
 * Return: Always 0
 */
int my_env(cmds_t *command)
{
	print_mylist_s(command->env);
	return (0);
}
