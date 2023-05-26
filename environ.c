#include "shell.h"

/**
 * _myenv -this really prints the current environment
 * @info: this is really the Structure
 * containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
print_list_str(info->env);
return (0);
}

/**
 * _getenv - this really gets the value of an environ variable
 * @info: this is really the Structure containing
 * potential arguments.this is really Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
list_t *node = info->env;
char *v;

while (node)
{
v = starts_with(node->str, name);
if (v && *v)
return (v);
node = node->next;
}
return (NULL);
}

/**
 * _mysetenv - this really Initializes a new environment variable,
 * or modify an existing one
 * @info: this is really the Structure containing potential
 * arguments. Used to maintain
 * constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Incorrect number of arguements\n");
return (1);
}
if (_setenv(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}

/**
 * _myunsetenv - this is really the Remove
 * an environment variable
 * @info:this is really Structure containing potential
 * arguments.this is really  Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
int i;

if (info->argc == 1)
{
_eputs("Too few arguements.\n");
return (1);
}
for (i = 1; i <= info->argc; i++)
_unsetenv(info, info->argv[i]);

return (0);
}

/**
 * populate_env_list - this really populates env linked list
 * @info: this is really Structure containing potential arguments.
 * Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t g;

for (g = 0; environ[g]; g++)
add_node_end(&node, environ[g], 0);
info->env = node;
return (0);
}

