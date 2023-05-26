#include "simple.h"

int execute_shell(info_t *g, char **v)
{
ssize_t r = 0;
int builtin_ret = 0;
while (r != -1 && builtin_ret != -2)
{
clear_info(g);
if (interactive)
_puts("$ ");
_eputchar(BUF_FLUSH);
r = get_input(g);
if (r != -1)
{
set_info(g, v);
builtin_ret = find_builtin(g);
if (builtin_ret == -1)
find_command(g);
}
else if (is_interactive(g))
_putchar('\n');
free_info(g, 0);
}
write_history(g);
free_info(g, 1);
if (!is_interactive(g) && g->status)
exit(g->status);
if (builtin_ret == -2)
{
if (g->err_num == -1)
exit(g->status);
exit(g->err_num);
}
return (builtin_ret);
}
int find_builtin(info_t *g)
{
int i, builtin_ret = -1;
builtin_table builtins[] = {

{"exit", _myexit},
{"env", _myenv},
{"help", _myhelp},
{"history", _myhistory},
{"setenv", _mysetenv},
{"unsetenv", _myunsetenv},
{"cd", _mycd},
{"alias", _myalias},
{NULL, NULL}
};

for (i = 0; builtins[i].type; i++)
{
if (_strcmp(g->argv[0], builtins[i].type) == 0)
{
g->line_count++;
builtin_ret = builtins[i].func(g);
break;
}
}
return (builtin_ret);
}
void find_command(info_t *g)
{
char *path = NULL;
int i, count;
g->path = g->argv[0];
if (g->linecount_flag == 1)
{
g->line_count++;
g->linecount_flag = 0;
}
count = count_non_delim(g->arg);
if (count == 0)
return;
path = find_in_path(g, _getenv(g, "PATH="), g->argv[0]);
if (path)
{
g->path = path;
execute_command(g);
}
else
{
if ((is_interactive(g) || _getenv(g, "PATH=")
			|| g->argv[0][0] == '/') && is_command(g, g->argv[0]))
execute_command(g);
else if (*(g->arg) != '\n')
{
g->status = 127;
print_error(g, "not found\n");
}
}
}
void execute_command(info_t *g)
{
pid_t child_pid;
child_pid = fork();
if (child_pid == -1)
{
perror("Error:");
return;
}
if (child_pid == 0)
{
if (execve(g->path, g->argv, get_environ(g)) == -1)
{
free_info(g, 1);
if (errno == EACCES)
exit(126);
exit(1);
}
}
else
{
wait(&(g->status));
if (WIFEXITED(g->status))
{
g->status = WEXITSTATUS(g->status);
if (g->status == 126)
print_error(g, "Permission denied\n");
}
}
}

