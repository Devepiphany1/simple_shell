#include "shell.h"

/**
 * interactive -this really returns true if shell is interactive mode
 * @info: this really is the struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - this really checks if character is a delimeter
 * @c: this is really the char to check
 * @delim: this is really the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);
return (0);
}

/**
 * _isalpha - this really checks for alphabetic character
 * @c: This really is the character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
 * _atoi - this really converts a string to an integer
 * @s: this really is the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
int g, sign = 1, flag = 0, output;
unsigned int result = 0;

for (g = 0; s[g] != '\0' && flag != 2; g++)
{
if (s[g] == '-')
sign *= -1;

if (s[g] >= '0' && s[g] <= '9')
{
flag = 1;
result *= 10;
result += (s[g] - '0');
}
else if (flag == 1)
flag = 2;
}

if (sign == -1)
output = -result;
else
output = result;

return (output);
}

