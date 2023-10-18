#include "shell.h"
/**
 * handle_path - Fnd the full path to a command
 * @cmd: The command to search for in the PATH
 * Return: A pointer to the full path of the command or NULL if Not found
*/
char *handle_path(char *cmd)
{
	int i, size;
	struct stat _stat;
	char *env_path, *total_cmd, *folder;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &_stat) == 0) /*If the real path exist*/
				return (str_dup(cmd));
			return (NULL);
		}
	}
	env_path = _getenv("PATH");
	if (env_path == NULL) /*If PATH is not unset*/
		return (NULL);
	folder = strtok(env_path, ":");
	while (folder)
	{
		size = str_len(folder) + str_len(cmd) + 2; /* 2 '/' & '\0' */
		total_cmd = malloc(size);
		if (total_cmd)
		{
			str_cp(total_cmd, folder);
			str_cat(total_cmd, "/");
			str_cat(total_cmd, cmd);
			if (stat(total_cmd, &_stat) == 0)
			{
				FreeAndSetToNULL((void **)&env_path);
				return (total_cmd);
			}
			FreeAndSetToNULL((void **)&total_cmd);
			folder = strtok(NULL, ":");
		}
	}
	FreeAndSetToNULL((void **)&env_path);
	return (NULL);
}
