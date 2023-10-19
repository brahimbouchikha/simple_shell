#include "shell.h"

/**
 * intToStr - Convert int to string
 * @n: The input number to convert to srting
 * Return: The string
*/
char *intToStr(int n)
{
	int tmp = n, i, countDigits = 1;
	char *str;

	while (tmp / 10)
		countDigits++;
	str = (char *)malloc(countDigits + 1);
	if (str == NULL)
		return (NULL);
	i = countDigits - 1;
	while (n)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	str[countDigits] = '\0';
	return (str);
}

/**
 * is_PN - Check if str is a positive number
 * @str: The input string to check
 * Return: 1 if is +, 0 otherwise
*/
int is_PN(char *str)
{
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str == ' ')
			str++;

		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
/**
 * custom_atoi - Convert String to Int
 * @str: The input string to convert
 * Return: The converted int on succes, 0 otherwise
*/
int custom_atoi(char *str)
{
	int result = 0;

	if (is_PN(str) == 0)
		return (0);
	while (*str)
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result);
}
