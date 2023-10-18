#include "shell.h"

/**
 * dupler_ch - Copying certain characters from a text string.
 * @p_tostr:it the  PATH  of the string
 * @began: began the index
 * @end: end the index
 *
 * Return: pointer to new buffer
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

