#include "shell.h"

/**
 * builtin - Handle Builtin Functions
 * @argv: the Second parameter in builtin case
 * @index: index of execution
 * @st: satuts of last command
 * @cmd: array of commands
 * Return: 1 on sccess, 0 otherwise
*/
int builtin(char *argv, int index, int *st, char *cmd[])
{
	int result = 0;
	char *str;

	if (isBuiltin(cmd[0]) == 1)
	{
		str = cmd[0];
		result = 1;
		if (str_cmp(str, "exit") == 0)
			custom_exit(argv, index, st, cmd);
		else if (str_cmp(str, "env") == 0)
			custom_env(st, cmd);
		else if (str_cmp(str, "setenv") == 0)
			custom_setenv(st, cmd);
	}
	return (result);
}
