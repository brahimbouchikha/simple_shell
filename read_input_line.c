#include "shell.h"

/**
 * read_input_line - Read line from the input user
 * Return: the line readed
 *
*/

char *read_input_line(void)
{
	char *line = NULL;
	size_t sizeline = 0;
	ssize_t n;

	if (isatty(0))
		write(1, "$ ", 2);
	n = getline(&line, &sizeline, stdin);
	if (n == -1)
	{
		FreeAndSetToNULL((void **) &line);
		return (NULL);
	}
	return (line);
}
