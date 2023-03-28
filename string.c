#include "main.h"

/**
 * print_string - accepts a string and returns the same string
 * @arg_list: string accepted
 *
 * Return: string
 */
char *print_string(va_list arg_list)
{
	char *str;
	char *new_str;
	int len;

	str = va_arg(arg_list, char *);
	if(str == NULL)
		str = "(null)";

	len = _strlen(str);

	new_str = malloc(sizeof(char) * len + 1);
	if(new_str == NULL)
		return (NULL);

	return (_strcpy(new_str, str));
}
