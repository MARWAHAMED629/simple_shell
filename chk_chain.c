#include "shell.h"
/**
 * chk_chain - Check if the current string should be
 *  continued Based on the string type Basing on chain_deli.
 * @command:  parameter of the struct
 * @buff:  character of the buffer
 * @a: address a current position in buffers
 * @s: start position in buffers
 * @l: the  length of buffers
 *
 * Return: Void
 */
void chk_chain(cmds_t *command, char *buff, size_t *a, size_t s, size_t l)
{
	size_t z = *a;

	if (command->command_buff_types == CMD_AND)
	{
		if (command->last_statue)
		{
			buff[s] = 0;
			z = l;
		}
	}
	if (command->command_buff_types == CMD_OR)
	{
		if (!command->last_statue)
		{
			buff[s] = 0;
			z = l;
		}
	}

	*a = z;
}
