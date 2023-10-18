#include "shell.h"
/**
 * list_str - it return an array of strings of the list->string.
 * @h: head of node
 *
 * Return: array of the strings
 */
char **list_str(lists_t *h)
{
	lists_t *node = h;
	size_t z = lenght_list(h), k;
	char **s;
	char *string;

	if (!h || !z)
		return (NULL);
	s = malloc(sizeof(char *) * (z + 1));
	if (!s)
		return (NULL);
	for (z = 0; node; node = node->next, z++)
	{
		string = malloc(my_strlen(node->s) + 1);
		if (!string)
		{
			for (k = 0; k < z; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}

		string = my_strcpy(string, node->s);
		s[z] = string;
	}
	s[z] = NULL;
	return (s);
}






/**
 * nd_start_wth - returns node whose string starts with prefix
 * @n:  list head of noode
 * @pre: string prefix a match
 * @d: it is a next character after prefix to match.
 *
 * Return: match node or null
 */
lists_t *nd_start_wth(lists_t *n, char *pre, char d)
{
	char *pointer = NULL;

	while (n)
	{
		pointer = _start_with(n->s, pre);
		if (pointer && ((d == -1) || (*pointer == d)))
			return (n);
		n = n->next;
	}
	return (NULL);
}



/**
 * printing_mylist - print elements in the list.
 * @p: head of pointer of the node.
 *
 * Return: size of the list
 */
size_t printing_mylist(const lists_t *p)
{
size_t c = 0;

while (p)
{
_puts(conv_num(p->n, 10, 0));
my_putchar(':');
my_putchar(' ');
_puts(p->s ? p->s : "(nil)");
_puts("\n");
p = p->next;
c++;
}
return (c);
}

/**
 *lenght_list - lenght of the list
 * @l: first noode.
 *
 * Return: size the list
 */
size_t lenght_list(const lists_t *l)
{
size_t o = 0;
while (l)
{
l = l->next;
o++;
}
return (o);
}
