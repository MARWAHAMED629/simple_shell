#include "shell.h"

/**
 * pop_env_lists - populate envairoment linked of list
 * @command: the Structure containing potential args
 * Return: Always 0
 */
int pop_env_lists(cmds_t *command)
{
	lists_t *nd = NULL;
	size_t z;

	for (z = 0; environ[z]; z++)
		add_end_node(&nd, environ[z], 0);
	command->env = nd;
	return (0);
}
