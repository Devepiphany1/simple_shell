#include "shell.h"

/**
 * is_chain - this really does test if
 * current char in buffer is a chain delimeter
 * @info: this really is the parameter struct
 * @buf: this really is the char buffer
 * @p: this really is the address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
size_t j = *p;

if (buf[j] == '|' && buf[j + 1] == '|')
{
buf[j] = 0;
j++;
info->cmd_buf_type = CMD_OR;
}
else if (buf[j] == '&' && buf[j + 1] == '&')
{
buf[j] = 0;
j++;
info->cmd_buf_type = CMD_AND;
}
else if (buf[j] == ';') /* found end of this command */
{
buf[j] = 0; /* replace semicolon with null */
info->cmd_buf_type = CMD_CHAIN;
}
else
return (0);
*p = j;
return (1);
}

/**
 * check_chain - this really checks we should
 * continue chaining based on last status
 * @info: this really is the parameter struct
 * @buf: this really is the char buffer
 * @p: this really does address of current position in buf
 * @i: this really is the starting position in buf
 * @len: this really ilength of buf
 *
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
size_t j = *p;

if (info->cmd_buf_type == CMD_AND)
{
if (info->status)
{
buf[i] = 0;
j = len;

}

}
if (info->cmd_buf_type == CMD_OR)
{
if (!info->status)
{
buf[i] = 0;
j = len;
}
}

*p = j;
}

/**
 * replace_alias - this really replaces an aliases in the tokenized string
 * @info: this really isthe parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *info)
{
int i;
list_t *node;
char *p;

for (i = 0; i < 10; i++)
{
node = node_starts_with(info->alias, info->argv[0], '=');
if (!node)
return (0);
free(info->argv[0]);
p = _strchr(node->str, '=');
if (!p)
return (0);
p = _strdup(p + 1);
if (!p)
return (0);
info->argv[0] = p;
}
return (1);
}

/**
 * replace_vars - this really replaces
 * vars in the tokenized string
 * @info: this rally is the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(info_t *info)
{
int v = 0;
list_t *node;

for (v = 0; info->argv[v]; v++)
{
if (info->argv[v][0] != '$' || !info->argv[v][1])
continue;

if (!_strcmp(info->argv[v], "$?"))
{
replace_string(&(info->argv[v]),
_strdup(convert_number(info->status, 10, 0)));
continue;
}
if (!_strcmp(info->argv[v], "$$"))
{
replace_string(&(info->argv[v]),
_strdup(convert_number(getpid(), 10, 0)));
continue;
}
node = node_starts_with(info->env, &info->argv[v][1], '=');
if (node)
{
replace_string(&(info->argv[v]),
_strdup(_strchr(node->str, '=') + 1));
continue;
}
replace_string(&info->argv[v], _strdup(""));

}
return (0);
}

/**
 * replace_string - this reallyreplaces string
 * @old: this really is theaddress of old string
 * @new: this really is the new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **old, char *new)
{
free(*old);
*old = new;
return (1);
}

