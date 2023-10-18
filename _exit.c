#include "shell.h"
/**
 * my_exit - exit the program.
 * @argument: it's an array of arguments.
 * Return: doesn't return anything
 **/
void my_exit(char **argument)
{

if (argument[0] != NULL && my_strcmp(argument[0], "exit") == 0)
{
if (argument[1] != NULL)
{
int status = _atoi(argument[1]);
exit(status);
}
else
{
exit(EXIT_SUCCESS);
}
}
}
