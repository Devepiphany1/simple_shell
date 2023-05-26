#include "shell.h"

/**
 * _myhistory - this really displays the history list, one command
 * by line, preceded
 * with line numbers, starting at 0.
 * @info: this is really Structure containing potential arguments.
 * Used to maintain
 *  constant function prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
print_list(info->history);
return (0);
}

/**
 * unset_alias -this is really sets alias to string
 * @info: this is really the parameter struct
 * @str: this is really the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
char *p, c;
int ret;

p = _strchr(str, '=');
if (!p)
return (1);
c = *p;
*p = 0;
ret = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*p = c;
return (ret);
}

/**
 * set_alias - this really sets alias to string
 * @info: this is really the parameter struct
 * @str: this is really the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
char *p;

p = _strchr(str, '=');
if (!p)
return (1);
if (!*++p)
return (unset_alias(info, str));

unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - this really prints an alias string
 * @node: this is the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
char *p = NULL, *a = NULL;

if (node)
{
p = _strchr(node->str, '=');
for (a = node->str; a <= p; a++)
_putchar(*a);
_putchar('\'');
_puts(p + 1);
_puts("'\n");
return (0);
}
return (1);
}

/**
 * _myalias - this really mimics the alias builtin (man alias)
 * @info: this is the Structure containing potential arguments.
 * Used to maintain
 * constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
int g = 0;
char *v = NULL;
list_t *node = NULL;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}
for (g = 1; info->argv[g]; v++)
{
v = _strchr(info->argv[g], '=');
if (v)
set_alias(info, info->argv[g]);
else
print_alias(node_starts_with(info->alias, info->argv[g], '='));
}

return (0);
}

