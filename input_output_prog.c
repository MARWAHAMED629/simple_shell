#include "shell.h"

/**
 * Initializing_cmd  - initializes cmds_t structure.
 * @command: struct name.
 *
 * @av:argument
 */
void Initializing_cmd(cmds_t *command, char **av)
{
int m = 0;

command->filesn = av[0];
if (command->arg)
{
command->argv = splite_str(command->arg, " \t");
if (!command->argv)
{

command->argv = malloc(sizeof(char *) * 2);
if (command->argv)
{
command->argv[0] = my_dupler(command->arg);
command->argv[1] = NULL;
}
}
for (m = 0; command->argv && command->argv[m]; m++)
;
command->argcount = m;

replacement_alias(command);
replaced_vars(command);
}
}

/**
 * frees_cmds -  it a free cmd_t structure files.
 * @command: structure name
 * @all: true if frees all fields
 */
void frees_cmds(cmds_t *command, int all)
{
my_free_str(command->argv);
command->argv = NULL;
command->cmd_path = NULL;
if (all)
{
if (!command->command_buff)
free(command->arg);
if (command->env)
my_free_list(&(command->env));
if (command->cmd_history)
my_free_list(&(command->cmd_history));
if (command->alias)
my_free_list(&(command->alias));
my_free_str(command->environ);
command->environ = NULL;
all_free((void **)command->command_buff);
if (command->readfiledes > 2)
close(command->readfiledes);
my_putchar(BUF_FLUSH);
}
}




/**
 * clear_cmd - it initializing cmds_t structure
 * @command: struct name
 */
void clear_cmd(cmds_t *command)
{
	command->arg = NULL;
	command->argv = NULL;
	command->cmd_path = NULL;
	command->argcount = 0;
}
