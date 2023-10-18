#include "shell.h"
/**
 * my_strcmp - Compare to two strings.
 * @st1: The first string to compare.
 * @st2: The second string to compare.
 * Return: negative if st1 < st2,
 * and  positive
 * if st1 > st2, and zero if st1 == st2
 */

int my_strcmp(char *st1, char *st2)
{
	while (*st1 && *st2)
	{
		if (*st1 != *st2)
			return (*st1 - *st2);
		st1++;
		st2++;
	}
	if (*st1 == *st2)
		return (0);
	else
		return (*st1 < *st2 ? -1 : 1);
}
