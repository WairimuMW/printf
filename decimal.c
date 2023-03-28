#include "main.h"

/**
 * _itoa - converts an integer into a string
 * @div: multiple of 10
 * @length: length of number
 * @n: number to convert
 *
 * Return: resulting string
 */
char *_itoa(int div, int n, int length)
{
	char *str;
	int i = 0;

	str = malloc(sizeof(char) * length + 2);
	if(str == NULL)
		return (NULL);
	/* account for a negative sign */
	if(n < 0)
	{
		str[0] = '-';
		i++;
	}
	/* convert each digit to a string */
	while(n < 0)
	{
		str[i] = ((n / div) * -1 + '0');
		n %= div;
		div /= 10;
		i++;
	}
	/* positives */
	while(div >= 1)
	{
		str[i] = ((n / div) + '0');
		n %= div;
		div /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

/**
 * print_int - finds the length of an integer to be passed to _itoa
 * @arg_list: integer argument
 *
 * Return: integer as a string
 */
char *print_int(va_list arg_list)
{
	int div, n, length, temp;

	n = va_arg(arg_list, int);
	temp = n;
	div = 1;
	length = 0;

	/* since 0 has length 1 */
	if(n == 0)
	{
		length++;
		return (_itoa(div, n, length));
	}
	while(temp != 0)
	{
		length += 1;
		if(length > 1)
			div *= 10;
		temp /= 10;
	}

	return (_itoa(div, n, length));
}
