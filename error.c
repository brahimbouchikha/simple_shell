#include "shell.h"

/**
 * p_error - Handle and display error
 * @index: The counter
 * @name: The name of programme
 * @cmd: The input command
*/

void p_error(int index, char *name, char *cmd)
{
	char *str_indx, msg[] = ": not found\n";
	
	str_indx = intToStr(index);
	write(2, name, str_len(name));
	write(2, ": ", 2);
	write(2, str_indx, str_len(str_indx));
	write(2, ": ", 2);
	write(2, cmd, str_len(cmd));
	write(2, msg, str_len(msg));

	FreeAndSetToNULL((void **) &str_indx);
}
