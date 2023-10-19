#include "shell.h"

/**
 * main - main function
 * @argc: Number of arrguments
 * @argv: Artguement
 * Return: 0
*/

int main(int argc, char *argv[])
{
	char *readline = NULL,  **cmd_args = NULL;
	int status = 0, i = 0;

	(void) argc;
	while (1)
	{
		readline = read_input_line();
		if (readline == NULL)
		{
			if (isatty(0))
				write(1, "\n", 1);
			return (status);
		}
		i++;
		cmd_args = custom_toknizer(readline);
		if (!cmd_args)
			continue;
		if (builtin(argv[0], i, &status, cmd_args))
			continue;
		status =  exec_cmd(cmd_args, argv, i);
	}
}
