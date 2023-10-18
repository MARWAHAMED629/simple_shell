#include "shell.h"

/**
 * _history_shell - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @command: the Structure containing potential argument.
 * 
 *  Return: Always 0
 */
int _history_shell(cmds_t *command)
{
	printing_mylist(command->cmd_history);
	return (0);
}

