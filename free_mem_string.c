#include "shell.h"
/**
 * my_free_str - free a string of strings
 * @p: a string of strings
 */
void my_free_str(char **p)
{
	char **z = p;

	if (!p)
		return;
	while (*p)
		free(*p++);
	free(z);
}
