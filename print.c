#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	char *buffer, *str;
	int i = 0, j = 0, len = 0, total = 0;
	va_list arg_list;
	char *(*f)(va_list);

	if(format == NULL)
		return (-1);

	buffer = create_buffer();
	if(buffer == NULL)
		return (-1);

	va_start(arg_list, format);

	while(format[i] != '\0')
	{
		if(format[i] != '%')
		{
			len = check_buffer_overflow(buffer, len);
			buffer[len++] = format[i++];
			total++;
		}
		else
		{
			i++;
			/* single ending % */
			if(format[i] == '\0')
			{
				va_end(arg_list);
				free(buffer);
				return (-1);
			}
			/* double % */
			if(format[i] == '%')
			{
				len = check_buffer_overflow(buffer, len);
				buffer[len++] = format[i];
				total++;
			}
			else
			{
				/* get the appropriate function */
				f = get_func(format[i]);
				if(f == NULL)
				{
					len = check_buffer_overflow(buffer, len);
					buffer[len++] = '%';
					total++;
					buffer[len++] = format[i];
					total++;
				}
				else
				{
					str = f(arg_list);
					if(str == NULL)
					{
						va_end(arg_list);
						free(buffer);
						return (-1);
					}
					if(format[i] == 'c' && str[0] == '\0')
					{
						len = check_buffer_overflow(buffer, len);
						buffer[len++] = '\0';
						total++;
					}
					j = 0;
					while(str[j] != '\0')
					{
						len = check_buffer_overflow(buffer, len);
						buffer[len++] = str[j];
						total++;
						j++;
					}
					free(str);
				}
			}
			i++;
		}
	}
	print_buffer(buffer, arg_list, len);
	return (total);
}
