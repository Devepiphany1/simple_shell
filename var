#include "simple.h"

/**
 * get_environ -this returns the string array copy of our environment
 * @g: Structure containing potential arguments.
 * Used to maintain constant function prototype.
 * Return: Always 0
 */
char **get_environ(info_t *g)
{
	if (!g->environ || g->env_changed)
	{
		g->environ = list_to_strings(g->env);
		g->env_changed = 0;
	}

	return (g->environ);
}

/**
 * unsetenv_custom - Remove an environment variable
 * @g: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int unsetenv_custom(info_t *g, char *var)
{
	list_t *node = g->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			g->env_changed = delete_node_at_index(&(g->env), i);
			i = 0;
			node = g->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (g->env_changed);
}

/**
 * setenv_custom - Initialize a new environment variable,
 * or modify an existing one
 * @g: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 * Return: Always 0
 */
int setenv_custom(info_t *g, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
			_strcpy(buf, var);
			_strcat(buf, "=");
			_strcat(buf, value);
			node = g->env;
			while (node)
			{
				p = starts_with(node->str, var);
				if (p && *p == '=')
				{
					free(node->str);
					node->str = buf;
					g->env_changed = 1;
					return (0);
				}
				node = node->next;
			}
			add_node_end(&(g->env), buf, 0);
			free(buf);
			g->env_changed = 1;
			return (0);
}

