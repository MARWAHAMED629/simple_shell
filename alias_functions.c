#include "shell.h"




/**
 * alias_print - print an alias string
 * @n: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int alias_print(lists_t *n)
{
char *b = NULL, *z = NULL;
if (n)
{
b = _stchr(n->s, '=');
for (z = n->s; z <= b; z++)
my_putchar(*z);
my_putchar('\'');
_puts(b + 1);
_puts("'\n");
return (0);
}
return (1);
}






/**
 * un_alias - sets alias to string
 * @command: parameter struct
 * @s: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int un_alias(cmds_t *command, char *s)
{
char *p, c;
int r;
p = _stchr(s, '=');
if (!p)
return (1);
c = *p;
*p = 0;
r =  remove_i_node(&(command->alias),
get_index_node(command->alias, nd_start_wth(command->alias, s, -1)));
*p = c;
return (r);
}



/**
 * run_alias - set of alias to string
 * @command: the parameter of  struct
 * @string: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int run_alias(cmds_t *command, char *string)
{
char *pointer;
pointer = _stchr(string, '=');
if (!pointer)
return (1);
if (!*++pointer)
return (un_alias(command, string));
un_alias(command, string);
return (add_end_node(&(command->alias), string, 0) == NULL);
}




/**
 * my_alias - mimics the alias builtin (man alias)
 * @command: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int my_alias(cmds_t *command)
{
int z = 0;
char *b = NULL;
lists_t *node = NULL;
if (command->argcount == 1)
{
node = command->alias;
while (node)
{
alias_print(node);
node = node->next;
}
return (0);
}
for (z = 1; command->argv[z]; z++)
{
b = _stchr(command->argv[z], '=');
if (b)
run_alias(command, command->argv[z]);
else
alias_print(nd_start_wth(command->alias, command->argv[z], '='));
}
return (0);
}
