#include "main.h"

/**
 * rot13 - encrypts a string using rot13
 * @arg_list: string to encrypt
 *
 * Return: resulting string
 */
char *rot13(va_list arg_list)
{
	char *str, *new_str;
	int i = 0;

	str = va_arg(arg_list, char *);

	/* allocate memory to new string */
	new_str = malloc(sizeof(char) * (_strlen(str) + 1));
	if(new_str == NULL)
		return (NULL);

	/* iterate through str and assign rot13 characters to new_str */
	while(str[i] != '\0')
	{
		if((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A' && str[i] <= 'M'))
			new_str[i] = str[i] + 13;
		else if((str[i] >= 'n' && str[i] <= 'z') || (str[i] >= 'N' && str[i] <= 'Z'))
			new_str[i] = str[i] - 13;
		else
			new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';

	return (new_str);
}
