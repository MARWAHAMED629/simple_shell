#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

#define PATH_FOUND 1
#define PATH_NOT_FOUND 0
#define _GNU_SOURCE





/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3


#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096


#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2


#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1




/**
 * struct lists_s - A singly linked list for storing integer and string pairs.
 * @n: An integer value.
 * @s: A string value.
 * @next: A pointer to the next node.
 */
typedef struct lists_s
{
	int        n;
	char      *s;
	struct lists_s	*next;
} lists_t;









typedef struct cmmandInfo
{
	unsigned int line_c;
	char *arg;
	char **argv;
	char *cmd_path;
	int argcount;
	int error_v;
	int linec_f;
	char *filesn;
	lists_t *env;
	lists_t *cmd_history;
	lists_t *alias;
	char **environ;
	int env_change_f;
	int last_statue;

	char **command_buff;
	int command_buff_types;
	int readfiledes;
	int history_cline;
} cmds_t;



#define PIPELINE_MAX_COMMANDS 2
#define MAX_COMMANDS 10

/**
 * INFO_INIT - Macro to initialize a `cmmandInfo` structure
 */

#define CMD_INIT \
{0, NULL, NULL, NULL, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct built - A structure for built-in
 * commands and their associated functions.
 *
 * @t: The string representing the built-in command.
 * @function: A pointer to the function that handles the built-in command.
 */


typedef struct built
{
	char *t;
	int (*function)(cmds_t *);
} built_t;



int found_built(cmds_t *);
void found_cmds(cmds_t *);
int run_myshell(cmds_t *, char **);
void fork_command(cmds_t *);
int  cmd_path(cmds_t *, char *);
char *dupler_ch(char *, int, int);
char *file_path(cmds_t *, char *, char *);
int loophsh(char **);
void _print_in(char *);
int _print_char(char);
int _printfile_d(char a, int fdescrption);
int _pfiled(char *string, int filedes);
char *_stcopy(char *, char *, int);
char *_stcat(char *, char *, int);
char *_stchr(char *, char);
char **splite_str(char *, char *);
char **splite_str2(char *, char);
int my_alpha(int);
int _atoi(char *);
int error_atoi(char *);
void err_print(cmds_t *, char *);
int my_print_cust(int, int);
int my_strlen(char *);
int my_strcmp(char *, char *);
char *_start_with(const char *, const char *);
char *my_strcat(char *, char *);
char *my_strcpy(char *, char *);
char *my_dupler(const char *);
void _puts(char *);
int my_putchar(char);
char *_memoryset(char *, char, unsigned int);
void my_free_str(char **);
void *my_reallocate(void *, unsigned int, unsigned int);
int all_free(void **);
int interactive(cmds_t *);
int _delimeter(char, char *);
char *conv_num(long int, int, int);
void rv_comment(char *);
int _my_exit(cmds_t *);
int _my_change_direct(cmds_t *);
int _help_print(cmds_t *);
int _history_shell(cmds_t *);
int my_alias(cmds_t *);
ssize_t input_user(cmds_t *);
int get_line(cmds_t *, char **, size_t *);
void sigint_handler(int);
void clear_cmd(cmds_t *);
void Initializing_cmd(cmds_t *, char **);
void frees_cmds(cmds_t *, int);
char *_get_myenv(cmds_t *, const char *);
int my_env(cmds_t *);
int my_setenv(cmds_t *);
int myun_setenv(cmds_t *);
int pop_env_lists(cmds_t *);
char **get_myenviroment(cmds_t *);
int _myunsetenv(cmds_t *, char *);
int _mysetenv(cmds_t *, char *, char *);
char *got_history_file(cmds_t *command);
int w_history(cmds_t *command);
int r_history(cmds_t *command);
int builder_history_l(cmds_t *command, char *buff, int lineindex);
int renum_history(cmds_t *command);
lists_t *add_nd(lists_t **, const char *, int);
lists_t *add_end_node(lists_t **, const char *, int);
int replacement_alias(cmds_t *);
int replaced_vars(cmds_t *);
int replaces_str(char **, char *);
size_t print_mylist_s(const lists_t *);
int  remove_i_node(lists_t **, unsigned int);
void my_free_list(lists_t **);
size_t lenght_list(const lists_t *);
int chain_deli(cmds_t *, char *, size_t *);
void chk_chain(cmds_t *, char *, size_t *, size_t, size_t);
char **list_str(lists_t *);
size_t printing_mylist(const lists_t *);
lists_t *nd_start_wth(lists_t *, char *, char);
ssize_t get_index_node(lists_t *, lists_t *);

extern char **environ;

#endif
