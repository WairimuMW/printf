#include "main.h"

/**
 * _strlen - finds the length of a string
 * @str: string to check
 *
 * Return: length of string @str
 */
int _strlen(char *str)
{
	int len = 0;

	while(*str != '\0')
		len++, str++;

	return (len);
}
