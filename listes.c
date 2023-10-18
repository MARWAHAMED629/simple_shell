#include "shell.h"
/**
 * add_end_node - added  node to the end of the lists.
 * @h: a  head node
 * @string: string field of the  node
 * @value:  index node to usge by the history
 *
 * Return: size of list
 */
lists_t *add_end_node(lists_t **h, const char *string, int value)
{
	lists_t *n_node, *node;

	if (!h)
		return (NULL);

	node = *h;
	n_node = malloc(sizeof(lists_t));
	if (!n_node)
		return (NULL);
	_memoryset((void *)n_node, 0, sizeof(lists_t));
	n_node->n = value;
	if (string)
	{
		n_node->s = my_dupler(string);
		if (!n_node->s)
		{
			free(n_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = n_node;
	}
	else
		*h = n_node;
	return (n_node);
}






/**
 * print_mylist_s -string list print it print the list_t linked lists.
 * @head:head of the noode
 *
 * Return: size of  the list
 */
size_t print_mylist_s(const lists_t *head)
{
	size_t i = 0;

	while (head)
	{
		_puts(head->s ? head->s : "(nil)");
		_puts("\n");
		head = head->next;
		i++;
	}
	return (i);
}



/**
 * my_free_list - free All THE Nodes of THE list
 * @h_pointer: name of the pointer to head the noode
 *
 * Return: void
 */
void my_free_list(lists_t **h_pointer)
{
	lists_t *n, *next_nd, *nhead;

	if (!h_pointer || !*h_pointer)
		return;
	nhead = *h_pointer;
	n = nhead;
	while (n)
	{
		next_nd = n->next;
		free(n->s);
		free(n);
		n = next_nd;
	}
	*h_pointer = NULL;

}

