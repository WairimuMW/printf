#include "main.h"

/**
 * create_buffer - ceates a buffer to hold the string until it's ready to be printed
 *
 * Return: pointer to the buffer created, NULL otherwise
 */
char *create_buffer(void)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if(buffer == NULL)
		return (NULL);

	return (buffer);
}

/**
 * print_buffer - prints the contents of the buffer
 * @buffer: buffer holding contents to be printed
 * @arg_list: argument list
 * @len: length of the string to be printed
 *
 * Return: None
 */
void print_buffer(char *buffer, va_list arg_list, int len)
{
	char *new_buffer;
	
	new_buffer = realloc(buffer, len); /* realloc to more accurate memory size */
	write(1, new_buffer, len); /* print contents of buffer */
	free(new_buffer); /* free buffer */
	va_end(arg_list); /* end arg_list traversal */
}

/**
 * check_buffer_overflow - prints everything in buffer then revert length back to 0
 * @buffer: buffer containing the string to print
 * @len: length of the string
 *
 * Return: length position
 */
int check_buffer_overflow(char *buffer, int len)
{
	if(len > 1020)
	{
		write(1, buffer, len);
		len = 0;
	}
	return (len);
}
