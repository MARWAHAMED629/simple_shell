#include "shell.h"
/**
 * file_path - find cmd in the PATH string
 * @find: the comand struct
 * @pstr:  PATH of the string
 * @command:  command  find in file.
 *
 * Return: full path of command to found or NULL
 */
char *file_path(cmds_t *find, char *pstr, char *command)
{
	int z = 0, c = 0;
	char *p;

	if (!pstr)
		return (NULL);
	if ((my_strlen(command) > 2) && _start_with(command, "./"))
	{
		if (cmd_path(find, command))
			return (command);
	}
	while (1)
	{
		if (!pstr[z] || pstr[z] == ':')
		{
			p = dupler_ch(pstr, c, z);
			if (!*p)
				my_strcat(p, command);
			else
			{
				my_strcat(p, "/");
				my_strcat(p, command);
			}
			if (cmd_path(find, p))
				return (p);
			if (!pstr[z])
				break;
			c = z;
		}
		z++;
	}
	return (NULL);
}





/**
 * dupler_ch - duplicates characters
 * @p_string: the PATH of the string
 * @s_index: start the index
 * @stp_index: stop the index
 *
 * Return: pointer in new buffer
 */
char *dupler_ch(char *p_string, int s_index, int stp_index)
{
	static char buff[1024];
	int a = 0, c = 0;

	for (c = 0, a = s_index; a < stp_index; a++)
		if (p_string[a] != ':')
			buff[c++] = p_string[a];
	buff[c] = 0;
	return (buff);
}

