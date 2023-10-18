#include "shell.h"

/**
 **_stcopy - copies a string
 *@d: the destination string to be copied to
 *@s: the source string
 *@v: the value of characters to be copied
 *Return: the contected string
 */
char *_stcopy(char *d, char *s, int v)
{
	int x, y;
	char *dest = d;

	x = 0;
	while (s[x] != '\0' && x < v - 1)
	{
		d[x] = s[x];
	x++;
	}
	if (x < v)
	{
		y = x;
		while (y < v)
		{
			d[y] = '\0';
			y++;
		}
	}
	return (dest);
}

/**
 **_stcat - concatenates two strings
 *@d:first string
 *@s: the second string
 *@v: the value of bytes that  to be maximally used
 *Return: the concatenated string
 */
char *_stcat(char *d, char *s, int v)
{
	int x, y;
	char *dest = d;

	x = 0;
	y = 0;
	while (d[x] != '\0')
		x++;
	while (s[x] != '\0' && y < v)
	{
		d[x] = s[y];
		x++;
		y++;
	}
	if (y < v)
		d[x] = '\0';
	return (dest);
}

/**
 **_stchr - locates a character in a string
 *@string: string to be parsed
 *@ch: character to looking for
 *Return: (string) a pointer to the memory area st
 */
char *_stchr(char *string, char ch)
{
	do {
		if (*string == ch)
			return (string);
	} while (*string++ != '\0');

	return (NULL);
}
