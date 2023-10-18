#include "shell.h"

/**
 **_memoryset - fills memory with a constant byte
 *@a: it's a pointer to the memory area
 *@c: it's byte to fill *a with
 *@z: it's amount of bytes to be fill
 *Return: (a) a pointer to the memory area a
 */
char *_memoryset(char *a, char c, unsigned int z)
{
	unsigned int x;

	for (x = 0; x < z; x++)
		a[x] = c;
	return (a);
}
