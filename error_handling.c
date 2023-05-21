#include "simple.h"

/**
 * _gputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _gputs(char *g)
{
	int v = 0;

	if (!g)
		return;
	while (g[v] != '\0')
	{
		_putchar(g[v]);
		v++;
	}
}

/**
 * _gputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _gputchar(char c)
{
	static int v;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || v >= WRITE_BUF_SIZE)
	{
		write(2, buf, v);
		v = 0;
	}
	if (c != BUF_FLUSH)
		buf[v++] = c;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int v;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || v >= WRITE_BUF_SIZE)
	{
		write(fd, buf, v);
		v = 0;
	}
	if (c != BUF_FLUSH)
		buf[v++] = c;
	return (1);
}

/**
 * _putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *g, int fd)
{
	int v = 0;

	if (!g)
		return (0);
	while (*g)
	{
		v += _putfd(*g++, fd);
	}
	return (v);
}
