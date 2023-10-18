#include "shell.h"
/**
 * found_built-   it  finds  the builtin command
 * @command: it is a parameter of the structure.
 *
 * Return: -1 if builtin not found,
 *			0 if builtin executes successfully,
 *			1 if builtin found but n't successfully,
 *			-2 if builtin signal exit()
 */
int found_built(cmds_t *command)
{
	int z, builtin_returns = -1;
	built_t builtin_t[] = {
		{"exit", _my_exit},
		{"env", my_env},
		{"help", _help_print},
		{"history", _history_shell},
		{"setenv", my_setenv},
		{"unsetenv", myun_setenv},
		{"cd",  _my_change_direct},
		{"alias", my_alias},
		{NULL, NULL}
	};

	for (z = 0; builtin_t[z].t; z++)
		if (my_strcmp(command->argv[0], builtin_t[z].t) == 0)
		{
			command->line_c++;
			builtin_returns = builtin_t[z].function(command);
			break;
		}
	return (builtin_returns);
}





/**
 * found_cmds -  it  finds a command in the PATH
 * @command: it is a parameter structure.
 *
 * Return: void
 */
void found_cmds(cmds_t *command)
{
	char *path = NULL;
	int c, n;

	command->cmd_path = command->argv[0];
	if (command->linec_f == 1)
	{
		command->line_c++;
		command->linec_f = 0;
	}
	for (c = 0, n = 0; command->arg[c]; c++)
		if (!_delimeter(command->arg[c], " \t\n"))
			n++;
	if (!n)
		return;

	path = file_path(command, _get_myenv(command, "PATH="), command->argv[0]);
	if (path)
	{
		command->cmd_path = path;
		fork_command(command);
	}
	else
	{
		if ((interactive(command) || _get_myenv(command, "PATH=")
			|| command->argv[0][0] == '/') && cmd_path(command, command->argv[0]))
			fork_command(command);
		else if (*(command->arg) != '\n')
		{
			command->last_statue = 127;
			err_print(command, "not found\n");
		}
	}
}

/**
 * fork_command - fork  exe thread to run the command
 * @command: the parameter of the struct
 *
 * Return: a void
 */
void fork_command(cmds_t *command)
{
pid_t child_pid;
child_pid = fork();
if (child_pid == -1)
{
perror("Error:");
return;
}
if (child_pid == 0)
{
if (execve(command->cmd_path, command->argv, get_myenviroment(command)) == -1)
{
frees_cmds(command, 1);
if (errno == EACCES)
exit(126);
exit(1);
}
}
else
{
wait(&(command->last_statue));
if (WIFEXITED(command->last_statue))
{
command->last_statue = WEXITSTATUS(command->last_statue);
if (command->last_statue == 126)
err_print(command, "Permission denied\n");
}
}
}
