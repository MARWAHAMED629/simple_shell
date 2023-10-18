#include "shell.h"

/**
 * my_strcpy - Copy one string to another.
 * @cps1: The destination string to copy to.
 * @cps2: The source string to copy from.
 *
 * Return: The pointer to the destination string (cps1).
 */

char *my_strcpy(char *cps1, char *cps2)
{
	int z = 0;

	if (cps1 == cps2 || cps2 == 0)
		return (cps1);
	while (cps2[z])
	{
		cps1[z] = cps2[z];
		z++;
	}
	cps1[z] = 0;
	return (cps1);
}


/**
 * my_strlen - count the num of charater in the string.
 * @string:the string to be checks.
 * Return: int length of string.
 */

int my_strlen(char *string)
{
	int y = 0;

	if (!string)
		return (0);

	while (*string++)
		y++;
	return (y);
}



/**
 * my_dupler - it  duplicate two  string
 * @s:  string  that be  duplicate
 *
 * Return: the pointer to the duplicate string.
 */
char *my_dupler(const char *s)
{
	int l = 0;
	char *r;

	if (s == NULL)
		return (NULL);
	while (*s++)
		l++;
	r = malloc(sizeof(char) * (l + 1));
	if (!r)
		return (NULL);
	for (l++; l--;)
		r[l] = *--s;
	return (r);
}


/**
 *_puts - it prints an input string.
 *@s:string to be print.
 *
 * Return: Nothing.
 */
void _puts(char *s)
{
int c = 0;

if (!s)
return;
while (s[c] != '\0')
{
my_putchar(s[c]);
c++;
}
}



/**
 * my_putchar - writes the character ch to stdout.
 * @ch: the  character to print,
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is  set  appropriately.
 */
int my_putchar(char ch)
{
static int p;
static char buf[WRITE_BUF_SIZE];

if (ch == BUF_FLUSH || p >= WRITE_BUF_SIZE)
{
write(1, buf, p);
p = 0;
}
if (ch != BUF_FLUSH)
buf[p++] = ch;
return (1);
}
