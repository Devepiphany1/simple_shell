#include "simple.h"

/**
 * _myenv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *g)
{
	print_list_str(g->env);
		return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *g, const char *v)
{
	list_t *g = g->env;
	char *p;

	while (g)
	{
		p = starts_with(g->str, v);
		if (p && *p)
				return (p);
		g = g->next

			return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(info_t *g)
{
	if (g->argc != 3)
			{
				_eputs("Incorrect number of arguements\n");
				return (1);
			}
	if (_setenv(g, g->argv[1], g->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _myunsetenv(info_t *g)
{
	int v;

	if (g->argc == 1
			{
_eputs("Too few arguements.\n");

return (1);
}
for (v = 1; v <= g->argc; v++)
_unsetenv(g, g->argv[v])
return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *g)
{
list_t *g = NULL;
size_t v;

for (v = 0; environ[v]; v++)
	add_node_end(&g, environ[v], 0);
g->env = g;
return (0);
}

