#include "simple.h"

/**
* is_chain - tests if current char in buffer is a chain delimiter
* @g: parameter struct
* @v: char buffer
* @p: address of current position in buffer
*
* Return: 1 if it's a chain delimiter, 0 otherwise
*/
int is_chain(info_t *g, char *v, size_t *p)
{
size_t j = *p;
if (v[j] == '|' && v[j + 1] == '|')
{
v[j] = 0;
j++;
g->cmd_buf_type = CMD_OR;
}
else if (v[j] == '&' && v[j + 1] == '&')
{
v[j] = 0;
j++;
g->cmd_buf_type = CMD_AND;
}
else if (v[j] == ';')
{
v[j] = 0;
g->cmd_buf_type = CMD_CHAIN;
}
else
return 0;
*p = j;
return 1;
}

/**
* check_chain - checks whether we
* should continue chaining based on last status
* @g: parameter struct
* @v: char buffer
* @p: address of current position in buffer
* @i: starting position in buffer
* @len: length of buffer
*
* Return: Void
*/
void check_chain(info_t *g, char *v, size_t *p, size_t i, size_t len)
{
size_t j = *p;
if (g->cmd_buf_type == CMD_AND)
{
if (g->status)
{
v[i] = 0;
j = len;
}
}
if (g->cmd_buf_type == CMD_OR)
{
if (!g->status)
{
v[i] = 0;
j = len;
}
}
*p = j;
}

/**
* replace_alias - replaces an alias in tokenized string
* @g: parameter struct
*
* Return: 1 if replaced, 0 otherwise
*/
int replace_alias(info_t *g)
{
int i;
list_t *node;
char *p;
for (i = 0; i < 10; i++)
{
node = node_starts_with(g->alias, g->argv[0], '=');
if (!node)
return 0;
free(g->argv[0]);
p = _strchr(node->str, '=');
if (!p)
return 0;
p = _strdup(p + 1);
if (!p)
return 0;
g->argv[0] = p;
}
return 1;
}

/**
* replace_vars - replaces variables in tokenized string
* @g: parameter struct
*
* Return: 1 if replaced, 0 otherwise
*/
int replace_vars(info_t *g)
{
int i = 0;
list_t *node;
for (i = 0; g->argv[i]; i++)
{
if (g->argv[i][0] != '$' || !g->argv[i][1])
continue;
if (!_strcmp(g->argv[i], "$ ? "))
{
replace_string(&(g->argv[i]), _strdup(convert_number(g->status, 10, 0)));
continue;
}
if (!_strcmp(g->argv[i], "$$"))
{
replace_string(&(g->argv[i]), _strdup(convert_number(getpid(), 10, 0)));
continue;
}
node = node_starts_with(g->env, &g->argv[i][1], '=');
if (node)
{
replace_string(&(g->argv[i]), _strdup(_strchr(node->str, '=') + 1));
continue;
}
replace_string(&g->argv[i], _strdup(""));
}
return 0;
}

/**
* replace_string - replaces string
* @old: address of old string
* @new: new string
*
* Return: 1 if replaced, 0 otherwise
*/
int replace_string(char **old, char *new)
{
free(*old);
*old = new;
return 1;
}
