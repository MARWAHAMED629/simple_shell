#include "shell.h"

/**
 * replaced_vars - replaced vars on the tokenization string
 * @command:  parameter of the struct
 *
 * Return: 1 if replaces, 0 otherwise
 */
int replaced_vars(cmds_t *command)
{
	int c = 0;
	lists_t *n;

	for (c = 0; command->argv[c]; c++)
	{
		if (command->argv[c][0] != '$' || !command->argv[c][1])
			continue;

		if (!my_strcmp(command->argv[c], "$?"))
		{
			replaces_str(&(command->argv[c]),
				my_dupler(conv_num(command->last_statue, 10, 0)));
			continue;
		}
		if (!my_strcmp(command->argv[c], "$$"))
		{
			replaces_str(&(command->argv[c]),
				my_dupler(conv_num(getpid(), 10, 0)));
			continue;
		}
		n = nd_start_wth(command->env, &command->argv[c][1], '=');
		if (n)
		{
			replaces_str(&(command->argv[c]),
				my_dupler(_stchr(n->s, '=') + 1));
			continue;
		}
		replaces_str(&command->argv[c], my_dupler(""));

	}
	return (0);
}


/**
 * replaces_str - the replaces strings
 * @o: it's address of old string
 * @n: it is a  new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replaces_str(char **o, char *n)
{
	free(*o);
	*o = n;
	return (1);
}





/**
 * replacement_alias - replaces an aliases in the tokenization of string.
 * @command: prameter of structttt.
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replacement_alias(cmds_t *command)
{
	int x;
	lists_t *n;
	char *z;

	for (x = 0; x < 10; x++)
	{
		n = nd_start_wth(command->alias, command->argv[0], '=');
		if (!n)
			return (0);
		free(command->argv[0]);
		z = _stchr(n->s, '=');
		if (!z)
			return (0);
		z = my_dupler(z + 1);
		if (!z)
			return (0);
		command->argv[0] = z;
	}
	return (1);
}

