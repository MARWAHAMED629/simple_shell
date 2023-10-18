#include "shell.h"
/**
 * w_history - it is creating  a  file, or append to an existing file
 * @command: is a parameter structure
 *
 * Return: 1 on success, else -1
 */
int w_history(cmds_t *command)
{
	ssize_t file_d;
	char *f_name = got_history_file(command);
	lists_t *nd = NULL;

	if (!f_name)
		return (-1);

	file_d = open(f_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(f_name);
	if (file_d == -1)
		return (-1);
	for (nd = command->cmd_history; nd; nd = nd->next)
	{
		_pfiled(nd->s, file_d);
		_printfile_d('\n', file_d);
	}
	_printfile_d(BUF_FLUSH, file_d);
	close(file_d);
	return (1);
}

/**
 * r_history - read the  history from the file
 * @command: is aparameter struct
 *
 * Return: history count if success, 0 otherwise
 */
int r_history(cmds_t *command)
{
int d, last = 0, lineindex = 0;
ssize_t fd, rdlenght, filesize = 0;
struct stat st;
char *buff = NULL, *f_name = got_history_file(command);
if (!f_name)
return (0);
fd = open(f_name, O_RDONLY);
free(f_name);
if (fd == -1)
return (0);
if (!fstat(fd, &st))
filesize = st.st_size;
if (filesize < 2)
return (0);
buff = malloc(sizeof(char) * (filesize + 1));
if (!buff)
return (0);
rdlenght = read(fd, buff, filesize);
buff[filesize] = 0;
if (rdlenght <= 0)
return (free(buff), 0);
close(fd);
for (d = 0; d < filesize; d++)
if (buff[d] == '\n')
{
buff[d] = 0;
builder_history_l(command, buff + last, lineindex++);
last = d + 1;
}
if (last != d)
builder_history_l(command, buff + last, lineindex++);
free(buff);
command->history_cline = lineindex;
while (command->history_cline-- >= HIST_MAX)
remove_i_node(&(command->cmd_history), 0);
renum_history(command);
return (command->history_cline);
}

/**
 * builder_history_l -  to added  entry to  the history linked list.
 * @command: Structure containing potential args.
 * @buff:it is a buffer
 * @lineindex:   it is a history lineindex, history count index.
 *
 * Return: Always 0
 */
int builder_history_l(cmds_t *command, char *buff, int lineindex)
{
	lists_t *nd = NULL;

	if (command->cmd_history)
		nd = command->cmd_history;
	add_end_node(&nd, buff, lineindex);

	if (!command->cmd_history)
		command->cmd_history = nd;
	return (0);
}

/**
 * renum_history - Renumbers it is a histories linked list after change.
 * @command: Structure containing potential arguments.
 *
 * Return: it's a  new history index.
 */
int renum_history(cmds_t *command)
{
	lists_t *node = command->cmd_history;
	int z = 0;

	while (node)
	{
		node->n = z++;
		node = node->next;
	}
	return (command->history_cline = z);
}


/**
 * got_history_file - gets the history file
 * @command: parameter struct
 *
 * Return: allocated string containg history file
 */

char *got_history_file(cmds_t *command)
{
	char *b, *direct;

	direct = _get_myenv(command, "HOME=");
	if (!direct)
		return (NULL);
	b = malloc(sizeof(char) * (my_strlen(direct) + my_strlen(HIST_FILE) + 2));
	if (!b)
		return (NULL);
	b[0] = 0;
	my_strcpy(b, direct);
	my_strcat(b, "/");
	my_strcat(b, HIST_FILE);
	return (b);
}
