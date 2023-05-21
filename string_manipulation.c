#include "simple.h"

/**
 * _gncpy - copies a string
 * @g: the destination string to be copied to
 * @v: the source string
 * @n: the amount of characters to be copied
 * Return: the concatenated string
 */
char *_gncpy(char *g, char *v, int n)
{
	int i, j;
	char *s = g;

	i = 0;
	while (v[i] != '\0' && i < n - 1)
	{
		g[i] = v[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			g[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * _gncat - concatenates two strings
 * @g: the first string
 * @v: the second string
 * @n: the amount of bytes to be maximally used
 * Return: the concatenated string
 */
char *_gncat(char *g, char *v, int n)
{
	int i, j;
	char *s = g;

	i = 0;
	j = 0;
	while (g[i] != '\0')
		i++;
	while (v[j] != '\0' && j < n)
	{
		g[i] = v[j];
		i++;
		j++;
	}
	if (j < n)
		g[i] = '\0';
	return (s);
}

/**
 * _gchr - locates a character in a string
 * @g: the string to be parsed
 * @v: the character to look for
 * Return: (g) a pointer to the memory area g
 */
char *_gchr(char *g, char v)
{
	do {
		if (*g == v)
			return (g);
	} while (*g++ != '\0');

	return (NULL);
}
