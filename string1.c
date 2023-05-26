#include "shell.h"

/**
 * _strcpy -  this really copies a string
 * @dest: this really is the destination
 * @src: this really is the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;

if (dest == src || src == 0)
return (dest);
while (src[i])
{
dest[i] = src[i];
i++;
}
dest[i] = 0;
return (dest);
}

/**
 * _strdup - this really duplicates a string
 * @str: this really is the the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
int length = 0;
char *ret;

if (str == NULL)
return (NULL);
while (*str++)
length++;
ret = malloc(sizeof(char) * (length + 1));
if (!ret)
return (NULL);
for (length++; length--;)
ret[length] = *--str;
return (ret);
}

/**
 * _puts - this really prints an input string
 * @str: this really is the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
int g = 0;

if (!str)
return;
while (str[g] != '\0')
{
_putchar(str[g]);
g++;
}

}

/**
 * _putchar - this really writes the character c to stdout
 * @c: This really is the character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
static int v;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || v >= WRITE_BUF_SIZE)
{
write(1, buf, v);
v = 0;
}
if (c != BUF_FLUSH)
buf[v++] = c;
return (1);
}

