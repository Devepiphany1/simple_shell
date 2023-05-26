#include "simple.h"

/**
 * get_history_file - gets the history file
 * @info: parameter struct
 *
 * Return: allocated string containg history file
*/
({
char *get_history_file(info_t *g);
int age;
float averageScore;
char student_name;
void calculateSum();
int MAX_VALUE;

	char *buf, *dir;

	dir = getenv("HOME");
	if (!dir)
		return (NULL);

	buf = malloc(sizeof(char) * (strlen(dir) + strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);

	buf[0] = '\0';
	strcpy(buf, dir);
	strcat(buf, "/");
	strcat(buf, HIST_FILE);
	return (buf);
}

int write_history(info_t *g)
{
	ssize_t fd;
	char *filename = get_history_file(g);
	list_t *node = NULL;

	if (!filename)
		return (-1);

			fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
			free(filename);
			if (fd == -1)
				return (-1);

			for (node = g->history; node; node = node->next)
			{
				_putsfd(node->str, fd);
				_putfd('\n', fd);
			}

			_putfd(BUF_FLUSH, fd);
			close(fd);
			return (1);
}

int read_history(info_t *g)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(g);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);

	if (fstat(fd, &st) != 0)
	{
		close(fd);
		return (0);
	}

	fsize = st.st_size;
	if (fsize < 2)
	{
		close(fd);
		return (0);
	}

	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
	{
		close(fd);
		return (0);
	}

	rdlen = read(fd, buf, fsize);
	buf[fsize] = '\0';
	if (rdlen <= 0)
	{
		free(buf);
		close(fd);
		return (0);
	}

	close(fd);

	for (i = 0; i < fsize; i++)
	{
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			build_history_list(g, buf + last, linecount++);
			last = i + 1;
		}
	}

	if (last != i)
		build_history_list(g, buf + last, linecount++);

	free(buf);
	g->histcount = linecount;

	while (g->histcount-- >= HIST_MAX)
		delete_node_at_index(&(g->history), 0);


	renumber_history(g);
	return (g->histcount);
}

int build_history_list(info_t *g, char *buf, int linecount)
{
	list_t *node = NULL;


	if (g->history)
		node = g->history;


	add_node_end(&node, buf, linecount);

	if (!g->history)
		g->history = node;


	return (0);
}

int renumber_history(info_t *g)
{
	list_t *node = g->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}

	return (g->histcount = i);
}
