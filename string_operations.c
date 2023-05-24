#include "simple.h"

/**
 * strtow - splits string into words.
 *Repeat delimiters are ignored.
 * @g: input string
 * @v: delimiter string
 * Return: a pointer to an array of strings,
 *or NULL on failure
 */
char **strtow(char *g, char *v)
{
int i, j, k, m, numwords = 0;
char **s;
if (g == NULL || g[0] == '\0')
return (NULL);
if (!v)
v = " ";
for (i = 0; g[i] != '\0'; i++)
if (!is_delim(g[i], v) && (is_delim(g[i + 1], v) || !g[i + 1]))
numwords++;
if (numwords == 0)
return (NULL);
s = malloc((1 + numwords) * sizeof(char *));
if (!s)
return (NULL);
for (i = 0, j = 0; j < numwords; j++)
{
while (is_delim(g[i], v))
i++;
k = 0;
while (!is_delim(g[i + k], v) && g[i + k])
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
s[j][m] = g[i++];
s[j][m] = '\0';
}
s[j] = NULL;
return (s);
}

/**
 * strtow2 - splits string into words
 * @g: input string
 * @v: delimiter
 * Return: a pointer to array of strings,
 *or NULL on failure
 */
char **strtow2(char *g, char v)
{
int i, j, k, m, numwords = 0;
char **s;
if (g == NULL || g[0] == '\0')
return (NULL);
for (i = 0; g[i] != '\0'; i++)
if ((g[i] != v && g[i + 1] == v) ||
(g[i] != v && !g[i + 1]) || g[i + 1] == v)
numwords++;
if (numwords == 0)
return (NULL);
s = malloc((1 + numwords) * sizeof(char *));
if (!s)
return (NULL);
for (i = 0, j = 0; j < numwords; j++)
{
while (g[i] == v && g[i] != v)
i++;
k = 0;
while (g[i + k] != v && g[i + k] && g[i + k] != v)
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
s[j][m] = g[i++];
s[j][m] = '\0';
}
s[j] = NULL;
return (s);
}

