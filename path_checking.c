#include "shell.h"

/**
 * cmd_path - determines if the file is  executable command
 * @command: the command structure.
 * @path: the path to  file
 *
 * Return: 1 if true, 0 otherwise
 */
int  cmd_path(cmds_t *command, char *path)
{
	struct stat s;

	(void)command;
	if (!path || stat(path, &s))
		return (0);

	if (s.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
