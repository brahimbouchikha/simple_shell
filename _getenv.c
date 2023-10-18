#include "shell.h"
/**
 * _getenv - Get the value of an environment variable.
 * @name: The name of the environment variable to retreive.
 *
 * Return: A pointer to the value of the variable, or NULL if not fount.
*/
char *_getenv(char *name)
{
	int i;
	char *temp, *env_key, *env_value, *env_value_cp;

	for (i = 0; environ[i]; i++)
	{
		temp = str_dup(environ[i]);
		env_key = strtok(temp, "=");
		if (str_cmp(env_key, name) == 0)
		{
			env_value = strtok(NULL, "\n");
			env_value_cp = str_dup(env_value);
			FreeAndSetToNULL((void **)&temp);
			return (env_value_cp);
		}
		FreeAndSetToNULL((void **)&temp);
	}
	return (NULL);
}
