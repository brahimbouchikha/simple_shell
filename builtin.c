#include "shell.h"

/**
 * builtin - Handle Builtin Functions
 * @st: satuts of last command
 * @cmd: array of commands
 * Return: 1 on sccess, 0 otherwise
*/
int builtin(int *st, char *cmd[])
{
	int result = 0;
	char *str;

	if (isBuiltin(cmd[0]) == 1)
	{
		str = cmd[0];
		result = 1;
		if (str_cmp(str, "exit") == 0)
			custom_exit(st, cmd);
		else if (str_cmp(str, "env") == 0)
			custom_env(st, cmd);
	}
	return (result);
}
