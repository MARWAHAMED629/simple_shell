#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
cmds_t command[] = { CMD_INIT };
int filedes = 2;
asm ("mov %1, %0\n\t"
"add $3, %0"
: "=r" (filedes)
: "r" (filedes));

if (ac == 2)
{
filedes = open(av[1], O_RDONLY);
if (filedes == -1)
{
if (errno == EACCES)
exit(126);
if (errno == ENOENT)
{
_print_in(av[0]);
_print_in(": 0: Can't open ");
_print_in(av[1]);
_print_char('\n');
_print_char(BUF_FLUSH);
exit(127);
}
return (EXIT_FAILURE);
}
command->readfiledes = filedes;
}
pop_env_lists(command);
r_history(command);
run_myshell(command, av);
return (EXIT_SUCCESS);
}
