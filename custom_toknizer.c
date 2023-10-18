#include "shell.h"
/**
 * custom_toknizer - Tokenize a string into an array of strings
 * @str: The input string to be tokenized
 *
 * Return: An array of strings containing the tokens,
*/

char **custom_toknizer(char *str)
{
	char **args = NULL, *arg = NULL, delm[] = " \t\n", *tmp = NULL;
	int n = 0, i = 0;

	if (!str)
		return (NULL);
	tmp = str_dup(str);
	arg = strtok(tmp, delm);
	if (arg == NULL)
	{
		FreeAndSetToNULL((void **) &str);
		FreeAndSetToNULL((void **) &tmp);
		return (NULL);
	}
	while (arg)
	{
		n++;
		arg = strtok(NULL, delm);
	}
	free(tmp);
	args = malloc(sizeof(char *) * (n + 1));

	if (!args)
	{
		FreeAndSetToNULL((void **)&str);
		return (NULL);
	}
	arg = strtok(str, delm);
	while (arg)
	{
		args[i] = str_dup(arg);
		arg = strtok(NULL, delm);
		i++;
	}
	args[i] = NULL;
	FreeAndSetToNULL((void **) &str);
	return (args);
}
