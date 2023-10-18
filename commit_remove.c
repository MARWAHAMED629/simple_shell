#include "shell.h"
/**
 * rv_comment - the function replace first instance of '#' with '\0'
 * @buff: address of the string to modify
 *
 * Return: Always 0;
 */
void rv_comment(char *buff)
{
	int z;

	for (z = 0; buff[z] != '\0'; z++)
		if (buff[z] == '#' && (!z || buff[z - 1] == ' '))
		{
			buff[z] = '\0';
			break;
		}
}
