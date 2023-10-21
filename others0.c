#include "shell.h"
/**
 * free_string_array - Deallocates memory for an array of strings
 * @array: The array of strings to be freed
 *
*/
void free_string_array(char **array)
{
	int i;

	if (!array)
		return;

	for (i = 0; array[i]; i++)
	{
		FreeAndSetToNULL((void **) &array[i]);
	}
		FreeAndSetToNULL((void **) &array);
}

/**
 * FreeAndSetToNULL - Free the memory of parameter
 * @param: Parameter to be free
*/
void FreeAndSetToNULL(void **param)
{
	if (*param != NULL)
		free(*param);
	*param = NULL;
}
/**
 * isBuiltin - Check if command is builtin
 * @str: The input command
 *
 * Return: 1 if is builtin, 0 otherwise
*/
int isBuiltin(char *str)
{
	int i;
	char *builttinFunc[] = {"exit", "env", "setenv"};

	for (i = 0; i < 3; i++)
	{
		if (str_cmp(str, builttinFunc[i]) == 0)
			return (1);
	}
	return (0);
}
