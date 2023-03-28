#include "main.h"

/**
 * get_func - contains options of the functions needed
 * @ident: identifier for a function
 *
 * Return: pointer to the function needed
 */
char *(*get_func(char ident))(va_list)
{
	int i = 0;
	print keys[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_int},
		{'i', print_int},
		{'b', print_binary},
		{'\0', NULL}
	};

	while(keys[i].id != '\0')
	{
		if(ident == keys[i].id)
			return (keys[i].f);
		i++;
	}
	return (NULL);
}
