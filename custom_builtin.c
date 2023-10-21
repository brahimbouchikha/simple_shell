#include "shell.h"
/**
 * custom_exit - Exit function
 * @argv: the Second parameter in builtin case
 * @index: index of execution
 * @st: satuts of last command
 * @cmd: array of commands
*/

void custom_exit(char *argv, int index, int *st, char *cmd[])
{
	int exitVal = (*st);
	char *str_indx, msg[] = ": exit: Illegal number: ";

	if (cmd[1])
	{
		if (custom_atoi(cmd[1]) != 0)
		{
			exitVal = custom_atoi(cmd[1]);
		}
		else
		{
		*st = 2;
		str_indx = intToStr(index);
		write(2, argv, str_len(argv));
		write(2, ": ", 2);
		write(2, str_indx, str_len(str_indx));
		write(2, msg, str_len(msg));
		write(2, cmd[1], str_len(cmd[1]));
		write(2, "\n", 1);
		FreeAndSetToNULL((void **) &str_indx);
		free_string_array(cmd);
		return;
		}
	}
	free_string_array(cmd);
	exit(exitVal);
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

void custom_setenv(int *st, char *cmd[])
{
	int i = 0;
	char *env = NULL, *tmpenv = NULL, *key = NULL;

	env = malloc(str_len(cmd[1]) + str_len(cmd[2]) + 2);
	strcpy(env, cmd[1]);
	strcat(env, "=");
	strcat(env, cmd[2]);

	while (environ[i])
	{
		tmpenv = str_dup(environ[i]);
		key = strtok(tmpenv, "=");
		if (str_cmp(key, cmd[1]) == 0)
		{
			*st = 0;
			if (env)
			{
				environ[i] = malloc(str_len(cmd[1]) + str_len(cmd[2]) + 2);
				str_cp(environ[i], env);
				FreeAndSetToNULL((void **)&env);
				FreeAndSetToNULL((void **)&tmpenv);
				free_string_array(cmd);
				return;
			}
		}
		FreeAndSetToNULL((void **)&tmpenv);
		i++;
		

	}
	environ[i] = malloc(str_len(cmd[1]) + str_len(cmd[2]) + 2);
	str_cp(environ[i], env);
	environ[i + 1] = NULL;
	free_string_array(cmd);
	FreeAndSetToNULL((void **)&env);
	*st = 0;
}
