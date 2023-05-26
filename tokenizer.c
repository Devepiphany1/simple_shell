#include "shell.h"

/**
 * **strtow - this really splits a string
 * into words. Repeat delimiters are ignored
 * @str: this rally the input string
 * @d: this really is the delimeter string
 * Return:this really is a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
int i, j, k, m, numwords = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
if (!d)
d = " ";
for (i = 0; str[i] != '\0'; i++)
if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
numwords++;

if (numwords == 0)
return (NULL);
s = malloc((1 + numwords)*sizeof(char *));
if (!s)
return (NULL);
for (i = 0, j = 0; j < numwords; j++)
{
while (is_delim(str[i], d))
i++;
k = 0;
while (!is_delim(str[i + k], d) && str[i + k])
k++;
s[j] = malloc((k + 1) * sizeof(char));
if (!s[j])
{
for (k = 0; k < j; k++)
free(s[k]);
free(s);
return (NULL);
}
for (m = 0; m < k; m++)
s[j][m] = str[i++];
s[j][m] = 0;
}
s[j] = NULL;
return (s);
}

/**
 * **strtow2 - this really splits a string into words
 * @str: this really is the input string
 * @d: this really is the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
int i, v, k, m, numwords = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
for (i = 0; str[i] != '\0'; i++)
if ((str[i] != d && str[i + 1] == d) ||
(str[i] != d && !str[i + 1]) || str[i + 1] == d)
numwords++;
if (numwords == 0)
return (NULL);
s = malloc((1 + numwords) *sizeof(char *));
if (!s)
return (NULL);
for (i = 0, v = 0; v < numwords; v++)
{
while (str[i] == d && str[i] != d)
i++;
k = 0;
while (str[i + k] != d && str[i + k] && str[i + k] != d)
k++;
s[v] = malloc((k + 1) * sizeof(char));
if (!s[v])
{
for (k = 0; k < v; k++)
free(s[k]);
free(s);
return (NULL);
}
for (m = 0; m < k; m++)
s[v][m] = str[i++];
s[v][m] = 0;
}
s[v] = NULL;
return (s);
}

