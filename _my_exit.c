 #include "shell.h"

/**
 * _my_exit - exit from the shell
 * @command: Structure containing potential argument use it ,
 *          constant function prototype.
 *  Return: exit status
 *         (0) if command.argv[0] != "exit"
 */
int _my_exit(cmds_t *command)
{
if (command->argv[1])
{
char *endptr;
long exit_status = strtol(command->argv[1], &endptr, 10);
if (*endptr != '\0' || exit_status < INT_MIN || exit_status > INT_MAX)
{
command->last_statue = 2;
err_print(command, "Illegal number: ");
_print_in(command->argv[1]);
_print_char('\n');
return (1);
}
command->error_v = (int)exit_status;
}
else
{
command->error_v = 0;
}
return (-2);
}
