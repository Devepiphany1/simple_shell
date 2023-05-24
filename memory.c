#include "simple.h"

/**
 * _custom_memset - fills memory with a constant byte
 * @g: the pointer to the memory area
 * @v: the byte to fill *g with
 * @n: the amount of bytes to be filled
 *
 * Return: a pointer to the memory area g
 */
char *_custom_memset(char *g, char v, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
g[i] = v;
return (g);
}

/**
 * free_string_array - frees an array of strings
 * @str_array: the array of strings
 */
void free_string_array(char **str_array)
{
char **ptr = str_array;

if (!str_array)
return;
while (*str_array)
free(*str_array++);
free(ptr);
}

/**
 * _custom_realloc - reallocates a block of memory
 * @ptr: pointer to the previous malloc'ated block
 * @old_size: byte size of the previous block
 * @new_size: byte size of the new block
 *
 * Return: pointer to the reallocated block of memory
 */
void *_custom_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *g;

if (!ptr)
return (malloc(new_size));
if (!new_size)
{
free(ptr);
return (NULL);
}
if (new_size == old_size)
return (ptr);

g = malloc(new_size);
if (!g)
return (NULL);

old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
g[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (g);
}
