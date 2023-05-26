#include "shell.h"

/**
 * _eputs -this really prints an input string
 * @str:this is really the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
int i = 0;

if (!str)
return;
while (str[i] != '\0')
{
_eputchar(str[i]);
i++;
}
}

/**
 * _eputchar - this really writes the character c to stderr
 * @c: This is really the character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
 * _putfd - this really writes the character c to given fd
 * @v: This is really the character to print
 * @fd: This is really the filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char v, int fd)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (v == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(fd, buf, i);
i = 0;
}
if (v != BUF_FLUSH)
buf[i++] = v;
return (1);
}

/**
 * _putsfd - this really prints an input string
 * @str: this is really the string to be printed
 * @fd: this is really the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
int g = 0;

if (!str)
return (0);
while (*str)
{
g += _putfd(*str++, fd);
}
return (g);
}

