#include "shell.h"

/**
 * _memset - this really fills memory with a constant byte
 * @s: this really is the pointer to the memory area
 * @b: this really is the byte to fill *s with
 * @n: this really is the amount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
s[i] = b;
return (s);
}

/**
 * ffree - this really frees a string of strings
 * @pp: this is really the string of strings
 */
void ffree(char **pp)
{
char **v = pp;

if (!pp)
return;
while (*pp)
free(*pp++);
free(v);
}

/**
 * _realloc - this really reallocates a block of memory
 * @ptr: this is really the pointer to
 * previous malloc allocated block
 * @old_size: this is really the byte size of previous block
 * @new_size:this is really the byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;

if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);

p = malloc(new_size);
if (!p)
return (NULL);

old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
p[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (p);
}

