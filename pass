#include "simple.h"

/**
 * is_executable_command - Determines if a file is an executable command.
 * @g: The info struct.
 * @v: Path to the file.
 *
 * Return: 1 if the file is an executable command, 0 otherwise.
 */
int is_executable_command(info_t *g, char *v)
{
struct stat st;

(void)g;
if (!v || stat(v, &st) != 0)
return (0);

if (st.st_mode & S_IFREG)
return (1);

return (0);
}

/**
 * duplicate_characters - Duplicates characters from a string.
 * @g: The string to duplicate characters from.
 * @start: Starting index.
 * @stop: Stopping index.
 *
 * Return: Pointer to the new buffer containing the duplicated characters.
 */
char *duplicate_characters(char *g, int start, int stop)
{
static char buffer[1024];
int i, k = 0;

for (i = start; i < stop; i++)
{
if (g[i] != ':')
buffer[k++] = g[i];
}

buffer[k] = '\0';
return (buffer);
}

/**
 * find_command_path - Finds the full path of a command in the PATH string.
 * @g: The info struct.
 * @v: The PATH string.
 * @command: The command to find.
 *
 * Return: The full path of the command if found, NULL otherwise.
 */
char *find_command_path(info_t *g, char *v, char *command)
{
int i = 0, current_pos = 0;
char *path;

if (!v)
return (NULL);

if ((_strlen(command) > 2) && starts_with(command, "./"))
{
if (is_executable_command(g, command))
return (command);
}

while (1)
{
if (!v[i] || v[i] == ':')
{
path = duplicate_characters(v, current_pos, i);
if (!*path)
_strcat(path, command);
else
{
_strcat(path, "/");
_strcat(path, command);
}

if (is_executable_command(g, path))
return (path);

if (!v[i])
break;

current_pos = i;
}

i++;
}

return (NULL);
}
