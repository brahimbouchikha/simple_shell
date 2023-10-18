#include "shell.h"

/**
 * str_cp - Copy the contents of one string into another
 * @d: The destination string
 * @s: The source string
 *
 * Return: Pointer to the destination string
*/

char *str_cp(char *d, char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		d[i] = s[i];
	d[i] = '\0';
	return (d);
}

/**
 * str_len - Get size of string
 * @str: String to calculate the size
 *  Return: lenght of string
*/

size_t str_len(char *str)
{
	size_t len;

	for (len = 0; str[len] != '\0'; )
		len++;
	return (len);
}

/**
 * str_cat - Concatenate two strings
 * @d: The destination string to which 'src' will be concatenated
 * @s: The source string that will be appended to 'dest'
 *
 * Return: pointer to the resulting string
*/

char *str_cat(char *d, char *s)
{
	char *ptr = d;

	while (*ptr)
		ptr++;
	while (*s)
	{
		*ptr = *s;
		ptr++;
		s++;
	}
	*ptr = *s;
	return (d);
}

/**
 * str_dup - Duplicate a C-string
 * @str: The input string to duplicate
 *
 * Return: duplicated string
*/
char *str_dup(const char *str)
{
	size_t length = 0, i;
	char *duplicate;

	if (str == NULL)
		return (NULL);
	while (str[length] != '\0')
		length++;
	duplicate = (char *)malloc(sizeof(char) * (length + 1));
	if (duplicate == NULL)
		return (NULL);
	for (i = 0; i <= length; i++)
		duplicate[i] = str[i];

	return (duplicate);
}

/**
 * str_cmp - Compares characters in both strings
 * @str1: The first input string
 * @str2: The second input string
 *
 * Return: 0 if strings are equal, 1 otherwise
*/

int str_cmp(char *str1, char *str2)
{
	int i;

	for (i = 0; str1[i] != '\0' || str2[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
			return (1);
	}
	return (0);
}
