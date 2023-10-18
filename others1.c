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
