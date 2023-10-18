#include "shell.h"
/**
 *my_reallocate - reallocates a block of memory
 * @pointer: pointer to pre malloc block
 * @old_s: old size the byte size of previous block
 * @new_s: new size the byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *my_reallocate(void *pointer, unsigned int old_s, unsigned int new_s)
{
	char *b;

	if (!pointer)
		return (malloc(new_s));
	if (!new_s)
		return (free(pointer), NULL);
	if (new_s == old_s)
		return (pointer);

	b = malloc(new_s);
	if (!b)
		return (NULL);

	old_s = old_s < new_s ? old_s : new_s;
	while (old_s--)
		b[old_s] = ((char *)pointer)[old_s];
	free(pointer);
	return (b);
}
