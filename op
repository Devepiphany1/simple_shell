#include "simple.h"
/**
 * clear_info - initializes info_t struct
 * @g: struct address
 */
void clear_info(info_t *g)
{
	g->arg = NULL;
	g->argv = NULL;
	g->path = NULL;
	g->argc = 0;
}

/**
 * set_info - initializes info_t struct
 * @g: struct address
 * @v: argument vector
 */
void set_info(info_t *g, char **v)
{
	int i = 0;

	g->fname = v[0];
	if (g->arg)
	{
		g->argv = strtow(g->arg, " \t");
			if (!g->argv)
			{
				g->argv = malloc(sizeof(char *) * 2);
				if (g->argv)
				{
					g->argv[0] = _strdup(g->arg);
					g->argv[1] = NULL;
				}
			}
		for (i = 0; g->argv && g->argv[i]; i++)
			;
		g->argc = i;

		replace_alias(g);
		replace_vars(g);
	}
}

/**
 * free_info - frees info_t struct fields
 * @g: struct address
 * @all: true if freeing all fields
 */
void free_info(info_t *g, int all)
{
	ffree(g->argv);
	g->argv = NULL;
	g->path = NULL;
	if (all)
	{
		if (!g->cmd_buf)
			free(g->arg);
		if (g->env)
			free_list(&(g->env));
		if (g->history)
			free_list(&(g->history));
		if (g->alias)
			free_list(&(g->alias));
		ffree(g->environ);
		g->environ = NULL;
		bfree((void **)g->cmd_buf);
		if (g->readfd > 2)
			close(g->readfd);
		_putchar(BUF_FLUSH);
	}
}
