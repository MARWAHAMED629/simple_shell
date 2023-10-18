#include "shell.h"
/**
 * my_strcat - Used to merge (connect) two text strings together.
 * @to_dest: it destination buff.
 * @to_res:  the source buffer.
 *
 * Return:  the pointer to the destanition of the buffer.
 **/
char *my_strcat(char *to_dest, char *to_res)
{
	char *r = to_dest;

	while (*to_dest)
		to_dest++;
	while (*to_res)
		*to_dest++ = *to_res++;
	*to_dest = *to_res;
	return (r);
}

/**
 * _start_with -it's checked if the one string starts with another
 * @s: it sentance of string to search
 * @w:it's the word to find in sentance .
 *
 * Return: address of next char s  or NULL
 */
char *_start_with(const char *s, const char *w)
{
	while (*w)
		if (*w++ != *s++)
			return (NULL);
	return ((char *)s);
}
