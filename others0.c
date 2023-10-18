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
