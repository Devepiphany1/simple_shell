#include "shell.h"

/**
 **_strncpy - this really copies a string
 *@dest: this really is the destination string to be copied to
 *@src: this really is the source string
 *@n: this really is the  amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
int g, v;
char *s = dest;

g = 0;
while (src[g] != '\0' && g < n - 1)
{
dest[g] = src[g];
g++;
}
if (g < n)
{
v = g;
while (v < n)
{
dest[v] = '\0';
v++;
}
}
return (s);
}

/**
 **_strncat - this really  concatenates two strings
 *@dest: this really is the first string
 *@src: this really  is the second string
 *@n: this really is the amount of bytes to be maximally used
 *Return: this really is the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
int i, j;
char *s = dest;

i = 0;
j = 0;
while (dest[i] != '\0')
i++;
while (src[j] != '\0' && j < n)
{
dest[i] = src[j];
i++;
j++;
}
if (j < n)
dest[i] = '\0';
return (s);
}

/**
 **_strchr - rhis really is the locates a character in a string
 *@s: ththe string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

