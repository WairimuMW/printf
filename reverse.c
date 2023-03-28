#include "main.h"

/**
 * rev_string - reverses a string
 * @arg_list: string to reverse
 *
 * Return: reversed string
 */
char *rev_string(va_list arg_list)
{
	char *reversed, *str;
	int len, j, i = 0;

	/* store argument to access once only */
	str = va_arg(arg_list, char *);
	if(str == NULL)
		str = "(null)";

	len = _strlen(str);

	/* allocate memory for reversed string */
	reversed = malloc(sizeof(char) * (len + 1));
	if(reversed == NULL)
		return (NULL);

	for(j = (len - 1); j >= 0; j--)
	{
		/* store the reversed string in new variable */
		reversed[i++] = str[j];
	}
	reversed[i] = '\0';

	return (reversed);
}
