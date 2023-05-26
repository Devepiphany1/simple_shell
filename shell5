#include "simple.h"
#include "team.c"
#include <stdio.h>
#include <stdlib.h>
/**
 * shell_exit - Exits the shell with a given exit status.
 * @info: Pointer to the info_t structure.
 *
 * Return: -2 to indicate shell exit with a given exit status.
 */
#include <stdlib.h>
int shell_exit(info_t *g)
{
    int exit_status;

    if (g->argv[1])
    {
      exit_status = string_to_integer(g->argv[1]);
        if (exit_status == -1)
        {
            g->status = 2;
            print_error(g, "Illegal number: ");
            _eputs(g->argv[1]);
            _eputchar('\n');
            return (1);
        }
    }
    // Missing closing bracket for the if statement//
    // and the shell_exit function

    // Additional code can be added here if necessary

} // Added closing bracket for the shell_exit function

g->err_num = -1;
return (-2);
}

/**
 * shell_cd - Changes the current directory of the shell process.
 * @info: Pointer to the info_t structure.
 *
 * Return: Always 0.
 */
int shell_cd(info_t *g)
{
char *current_dir, *new_dir, buffer[1024];
int chdir_ret;

current_dir = getcwd(buffer, 1024);
if (!current_dir)
_puts("TODO: >>getcwd failure emsg here<<\n");

if (!g->argv[1])
{
new_dir = _getenv(g, "HOME=");
		if (!new_dir)
			chdir_ret = chdir((new_dir = _getenv(g, "PWD=")) ? new_dir : "/");
		else
			chdir_ret = chdir(new_dir);
	}
	else if (_strcmp(g->argv[1], "-") == 0)
	{
		if (!_getenv(g, "OLDPWD="))
		{
			_puts(current_dir);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(g, "OLDPWD="));
		_putchar('\n');
		chdir_ret = chdir((new_dir = _getenv(g, "OLDPWD=")) ? new_dir : "/");
	}
	else
		chdir_ret = chdir(g->argv[1]);

	if (chdir_ret == -1)
	{
		print_error(g, "can't cd to ");
		_eputs(g->argv[1]);
		_eputchar('\n');
	}
	else
	{
		_setenv(g, "OLDPWD", _getenv(g, "PWD="));
		_setenv(g, "PWD", getcwd(buffer, 1024));


	return (0);
}

/**
 * shell_help - Displays help information.
 * @info: Pointer to the info_t structure.
 *
 * Return: Always 0.
 */
int shell_help(info_t *g)
{
	char **arg_array = g->argv;

	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* Temporary workaround to avoid unused warning */

	return (0);
}
