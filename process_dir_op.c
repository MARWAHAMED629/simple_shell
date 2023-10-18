#include "shell.h"
/**
 * _my_change_direct- changes the current directory of the process
 * @command: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _my_change_direct(cmds_t *command)
{
	char *n, *dir, buffer[1024];
	int chdir_ret;

	n = getcwd(buffer, 1024);
	if (!n)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!command->argv[1])
	{
		dir = _get_myenv(command, "HOME=");
		if (!dir)
			chdir_ret =
				chdir((dir = _get_myenv(command, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (my_strcmp(command->argv[1], "-") == 0)
	{
		if (!_get_myenv(command, "OLDPWD="))
		{
			_puts(n);
			my_putchar('\n');
			return (1);
		}
		_puts(_get_myenv(command, "OLDPWD=")),my_putchar('\n');
		chdir_ret =
			chdir((dir = _get_myenv(command, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(command->argv[1]);
	if (chdir_ret == -1)
	{
		 err_print(command, "can't cd to ");
		_print_in(command->argv[1]), _print_char('\n');
	}
	else
	{
		_mysetenv(command, "OLDPWD", _get_myenv(command, "PWD="));
		_mysetenv(command, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
