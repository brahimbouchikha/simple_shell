#include "shell.h"

/**
 * exec_cmd - Execute a command with arguments in a separate child process
 * @cmd: An array of pointers to characters
 *	(strings) representing the command to be executed
 * @argv: An array of pointers to characters
 *	(strings) representing the arguments for the command.
 * @index: The counter that count number of execution
 * Return: status
*/
int exec_cmd(char **cmd, char **argv, int index)
{
	pid_t child_pid;
	int status;
	char *total_cmd;

	total_cmd = handle_path(cmd[0]);
	if (total_cmd == NULL)
	{

		p_error(index, argv[0], cmd[0]);
		free_string_array(cmd);
		return (127);
	}

	child_pid = fork();
	if (child_pid == 0)
	{
	total_cmd = handle_path(cmd[0]);
		if (execve(total_cmd, cmd, environ) == -1)
		{
			FreeAndSetToNULL((void **)&total_cmd);
			free_string_array(cmd);
		}
	}
	else
	{
			waitpid(child_pid, &status, 0);
			free_string_array(cmd);
			FreeAndSetToNULL((void **)&total_cmd);
	}
	return (WEXITSTATUS(status));
}
