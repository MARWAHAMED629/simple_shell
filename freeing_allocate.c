#include "shell.h"

/**
 * all_free - freeing dynamically allocated memorya pointer and NULLs.
 * @add_p: add pointer the address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int all_free(void **add_p)
{
	if (add_p && *add_p)
	{
		free(*add_p);
		*add_p = NULL;
		return (1);
	}
	return (0);
}
