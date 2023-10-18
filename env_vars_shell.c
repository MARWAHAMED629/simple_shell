#include "shell.h"
/**
 * _mysetenv - Set up a new environmental variable or modify an existing.
 * @v: The environmental variable name.
 * @i:The value to set for the environmental variable.
 *  Return: Always 0
 */
int _mysetenv(cmds_t *command, char *v, char *i)
{
	char *buff = NULL;
	lists_t *nodes;
	char *z;

	if (!v || !i)
		return (0);

	buff = malloc(my_strlen(v) + my_strlen(i) + 2);
	if (!buff)
		return (1);
	my_strcpy(buff, v);
	my_strcat(buff, "=");
	my_strcat(buff, i);
	nodes = command->env;
	while (nodes)
	{
		z = _start_with(nodes->s, v);
		if (z && *z == '=')
		{
			free(nodes->s);
			nodes->s = buff;
			command->env_change_f = 1;
			return (0);
		}
		nodes = nodes->next;
	}
	add_end_node(&(command->env), buff, 0);
	free(buff);
	command->env_change_f = 1;
	return (0);
}

/**
 * _myunsetenv - Remove an environment variable
 * @command: Structure containing potential args.
 *  Return: 1 on delete, 0 otherwise
 * @v: it is a variables of the string envairoment.
 */
int _myunsetenv(cmds_t *command, char *v)
{
	lists_t *node = command->env;
	size_t c = 0;
	char *z;

	if (!node || !v)
		return (0);

	while (node)
	{
		z = _start_with(node->s, v);
		if (z && *z == '=')
		{
			command->env_change_f = remove_i_node(&(command->env), c);
			c = 0;
			node = command->env;
			continue;
		}
		node = node->next;
		c++;
	}
	return (command->env_change_f);
}

/**
 * get_myenviroment - Retrieve the string array
 * of shell environment variables
 * @command: A structure containing potential arguments
 * Return: A string array containing the shell environment
 */
char **get_myenviroment(cmds_t *command)
{
	if (!command->environ || command->env_change_f)
	{
		command->environ = list_str(command->env);
		command->env_change_f = 0;
	}

	return (command->environ);
}
