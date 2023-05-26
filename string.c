#include "shell.h"

/**
 * _strlen - this rally returns the length of a string
 * @s: this really is the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
int g = 0;

if (!s)
return (0);

while (*s++)
g++;
return (g);
}

/**
 * _strcmp - this really performs lexicogarphic comparison of two strangs.
 * @s1: this really is the first strang
 * @s2: this really is the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - this really checks if needle starts with haystack
 * @haystack: this really is the string to search
 * @needle: this really is the substring to find
 *
 * Return: this really does address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
 * _strcat - this really concatenates two strings
 * @dest: this really is the destination buffer
 * @src: this really is the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
char *ret = dest;

while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}

