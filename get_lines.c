#include "shell.h"

/**
 * in_buffer - it is an input  buffers chain commands
 * @command: a parameter  of struct
 * @b: the  name of the  buffer.
 * @lenght: name  of lenght variables.
 *
 * Return: byte read
 */
ssize_t in_buffer(cmds_t *command, char **b, size_t *lenght)
{
ssize_t x = 0;
size_t lenght_b = 0;
if (!*lenght)
{
free(*b);
*b = NULL;
signal(SIGINT, sigint_handler);
x = getline(b, &lenght_b, stdin);
x = get_line(command, b, &lenght_b);
if (x > 0)
{
if ((*b)[x - 1] == '\n')
{
(*b)[x - 1] = '\0';
x--;
}
command->linec_f = 1;
rv_comment(*b);
builder_history_l(command, *b, command->history_cline++);
{
*lenght = x;
command->command_buff = b;
}
}
}
return (x);
}



/**
 * read_buffer - read the buffer
 * @command: the parameter struct
 * @b: the buffer
 * @s: size
 *
 * Return: z
 */
ssize_t read_buffer(cmds_t *command, char *b, size_t *s)
{
ssize_t z = 0;
if (*s)
return (0);
z = read(command->readfiledes, b, READ_BUF_SIZE);
if (z >= 0)
*s = z;
return (z);
}

/**
 * get_line -  it get  next line an input from STDIN
 * @command: it is a parameter of struct
 * @pointer: name of the pointer
 * @len: size lenght of preallocate pointer if n't NULL
 *
 * Return: x.
 */
int get_line(cmds_t *command, char **pointer, size_t *len)
{
static char buff[READ_BUF_SIZE];
static size_t z, l;
size_t n;
ssize_t o = 0, x = 0;
char *po = NULL, *n_point = NULL, *d;
po = *pointer;
if (po && l)
x = *len;
if (z == l)
z = l = 0;
o = read_buffer(command, buff, &l);
if (o == -1 || (o == 0 && l == 0))
return (-1);
d = _stchr(buff + z, '\n');
n = d ? 1 + (unsigned int)(d - buff) : l;
n_point = my_reallocate(po, x, x ? x + n : n + 1);
if (!n_point)
return (po ? free(po), -1 : -1);
if (x)
_stcat(n_point, buff + z, n - z);
else
_stcopy(n_point, buff + z, n - z + 1);
x += n - z;
z = n;
po = n_point;
if (len)
*len = x;
*pointer = po;
return (x);
}

/**
 * sigint_handler - it  ctrl-C
 * @sig_n: it a signal number.
 *
 * Return: void
 */
void sigint_handler(__attribute__((unused))int sig_n)
{
_puts("\n");
_puts("$ ");
my_putchar(BUF_FLUSH);
}

/**
 * input_user - get a lines min  new line.
 * @command: it is a parameter struct
 *
 * Return: byte read
 */
ssize_t input_user(cmds_t *command)
{
static char *buf;     /* command chain buffer */
static size_t i, j, len;
ssize_t r = 0;
char **buf_p = &(command->arg), *p;
my_putchar(BUF_FLUSH);
r = in_buffer(command, &buf, &len);
if (r == -1)
return (-1);
if (len)
{
j = i;           /* init new iterator to currents buffers  position */
p = buf + i;     /* got pointer for the return */
chk_chain(command, buf, &j, i, len);
while (j < len)  /* iterate  semicolon or the end */
{
if (chain_deli(command, buf, &j))
break;
j++;
}     /* increment past null ';'' */
i = j + 1;
if (i >= len)
{
i = len = 0;                      /* Reset position, length */
command->command_buff_types = CMD_NORM;
}
*buf_p = p;         /* pass back pointer to current command position */
return (my_strlen(p));  /* return of the length on current command */
}
*buf_p = buf;               /*Not a chain, pass back buf from input_user()*/
return (r);                 /* Return length buffers from input_user() */
}
