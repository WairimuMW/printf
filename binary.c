#include "main.h"

/**
 * print_binary - converts an integer to binary
 * @arg_list: integer to be converted
 *
 * Return: string of the binary result
 */
char *print_binary(va_list arg_list)
{
	char *str;
	int i, k, j = 0, two = 1;

	k = va_arg(arg_list, int);
	i = k;

	str = malloc(sizeof(char) * 33);
	if(str == NULL)
		return (NULL);

	/* negative numbers */
	if(k < 0)
	{
		str[0] = 1 + '0';
		j++;
		k *= -1;
		i *= -1;
	}

	while(k > 1)
	{
		k /= 2;
		two *= 2;
	}

	while(two > 0)
	{
		str[j++] = (i / two + '0');
		i %= two;
		two /= 2;
	}
	str[j] = '\0';

	return (str);
}
