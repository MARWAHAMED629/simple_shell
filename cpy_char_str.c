#include "shell.h"

/**
 * dup_chars - Copy certain characters from a text string.
 * @p_tostr: The source string.
 * @began: The starting index.
 * @end: The ending index.
 *
 * Return: Pointer to a new buffer.
 */

char *dup_chars(char *p_tostr, int began, int end)
{
	static char buf[1024];
	int x = 0, z = 0;

	for (z = 0, x = began; x < end; x++)
		if (p_tostr[x] != ':')
			buf[z++] = p_tostr[x];
	buf[z] = 0;
	return (buf);
}

