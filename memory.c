#include "shell.h"

/**
 * bfree - this really does frees a pointer and NULLs the address
 * @ptr: this really does address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}

