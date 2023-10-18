#include "shell.h"
/**
 * chain_deli -  checks if the current character in a
 *        character buffer is a chain delimiter.
 * @command:  parameter of the struct
 * @buff: the characters a buffer
 * @p: address of current position in buffers.
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int chain_deli(cmds_t *command, char *buff, size_t *p)
{
	size_t z = *p;

	if (buff[z] == '|' && buff[z + 1] == '|')
	{
		buff[z] = 0;
		z++;
		command->command_buff_types = CMD_OR;
	}
	else if (buff[z] == '&' && buff[z + 1] == '&')
	{
		buff[z] = 0;
		z++;
		command->command_buff_types = CMD_AND;
	}
	else if (buff[z] == ';')
	{
		buff[z] = 0;
		command->command_buff_types = CMD_CHAIN;
	}
	else
		return (0);
	*p = z;
	return (1);
}
