#include "main.h"

/**
 * print_char - converts a char to a string
 * @arg_list: character
 *
 * Return: resulting string
 */
char *print_char(va_list arg_list)
{
	char *str;
	char c;

	c = va_arg(arg_list, int);
	
	if(c == 0)
		c = '\0';

	str = malloc(sizeof(char) * 2);
	if(str == NULL)
		return (NULL);
	str[0] = c;
	str[1] = '\0';

	return (str);
}
