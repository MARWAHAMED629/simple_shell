#include "shell.h"

/**
 * add_nd - added the node to  start of the lists
 * @h: head of the  node
 * @string:  fiele string of the node.
 * @v:  index node usge by history.
 *
 * Return: size of list
 */
lists_t *add_nd(lists_t **h, const char *string, int v)
{
	lists_t *new_h;

	if (!h)
		return (NULL);
	new_h = malloc(sizeof(lists_t));
	if (!new_h)
		return (NULL);
	_memoryset((void *)new_h, 0, sizeof(lists_t));
	new_h->n = v;
	if (string)
	{
		new_h->s = my_dupler(string);
		if (!new_h->s)
		{
			free(new_h);
			return (NULL);
		}
	}
	new_h->next = *h;
	*h = new_h;
	return (new_h);
}


/**
 * remove_i_node - Remove index the node  give index
 * @h: a head of the noode.
 * @i: it is a index of node to want (delet)
 *
 * Return: 1 on success, 0 on fail
 */
int remove_i_node(lists_t **h, unsigned int i)
{
	lists_t *n, *previous_n;
	unsigned int c = 0;

	if (!h || !*h)
		return (0);

	if (!i)
	{
		n = *h;
		*h = (*h)->next;
		free(n->s);
		free(n);
		return (1);
	}
	n = *h;
	while (n)
	{
		if (c == i)
		{
			previous_n->next = n->next;
			free(n->s);
			free(n);
			return (1);
		}
		c++;
		previous_n = n;
		n = n->next;
	}
	return (0);
}



/**
 * get_index_node - it is get an index of the node
 * @h: head of the node
 * @n: noode name
 *
 * Return: index of the node or -1
 */
ssize_t get_index_node(lists_t *h, lists_t *n)
{
	size_t c = 0;

	while (h)
	{
		if (h == n)
			return (c);
		h = h->next;
		c++;
	}
	return (-1);

}

