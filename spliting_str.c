#include "shell.h"

/**
 * **splite_str - it splits a string into words,using multiple delimiters.
 * @st: the string input.
 * @del:delimeter string
 * Return: a pointer to an array of strings, or NULL on fail.
 */

char **splite_str(char *st, char  *del)
{
	int x, z, l, n, outwords = 0;
	char **s;

	if (st == NULL || st[0] == 0)
		return (NULL);
	if (!del)
		del = " ";
	for (x = 0; st[x] != '\0'; x++)
		if (!_delimeter(st[x], del) && (_delimeter(st[x + 1], del) || !st[x + 1]))
			outwords++;

	if (outwords == 0)
		return (NULL);
	s = malloc((1 + outwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (x = 0, z = 0; z < outwords; z++)
	{
		while (_delimeter(st[x], del))
			x++;
		l = 0;
		while (!_delimeter(st[x + l], del) && st[x + l])
			l++;
		s[z] = malloc((l + 1) * sizeof(char));
		if (!s[z])
		{
			for (l = 0; l < z; l++)
				free(s[l]);
			free(s);
			return (NULL);
		}
		for (n = 0; n < l; n++)
			s[z][n] = st[x++];
		s[z][n] = 0;
	}
	s[z] = NULL;
	return (s);
}

/**
 * **splite_str2 - splits a string into words
 * @string:string input
 * @del: delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **splite_str2(char *string, char del)
{
int x, y, z, n, countwd = 0;
char **st;
if (string == NULL || string[0] == 0)
return (NULL);
for (x = 0; string[x] != '\0'; x++)
if ((string[x] != del && string[x + 1] == del) ||
(string[x] != del && !string[x + 1]) || string[x + 1] == del)
countwd++;
if (countwd == 0)
return (NULL);
st = malloc((1 + countwd)*sizeof(char *));
if (!st)
return (NULL);
for (x = 0, y = 0; y < countwd; y++)
{
while (string[x] == del && string[x] != del)
x++;
z = 0;
while (string[x + z] != del && string[x + z] && string[x + z] != del)
z++;
st[y] = malloc((z + 1) * sizeof(char));
if (!st[y])
{
for (z = 0; z < y; z++)
free(st[z]);
free(st);
return (NULL);
}
for (n = 0; n < z; n++)
st[y][n] = string[x++];
st[y][n] = 0;
}
st[y] = NULL;
return (st);
}
