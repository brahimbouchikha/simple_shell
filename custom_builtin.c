#include "shell.h"
/**
 * custom_exit - Exit function
 * @st: satuts of last command
 * @cmd: array of commands
*/

void custom_exit(int *st, char *cmd[])
{
	free_string_array(cmd);
	exit(*st);
}

/**
 * custom_env - Print environ variable
 * @st: satuts of last command
 * @cmd: array of commands
*/

void custom_env(int *st, char *cmd[])
{
	int i = 0;

	while (environ[i])
	{
		write(1, environ[i], str_len(environ[i]));
		write(1, "\n", 1);
		i++;
	}
	*st = 0;
	free_string_array(cmd);
}
