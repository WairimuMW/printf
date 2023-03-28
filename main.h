#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h> /* malloc(), free() */
#include <stdarg.h> /* va_start(), va_end(), va_copy(), va_arg() */
#include <unistd.h> /* write() */

/**
 * struct dtypes - structure
 * @id: identifier of the data type to print (eg. d represents int)
 * @f: pointer to functions associated with the identifiers (eg. print_int)
 */
typedef struct dtypes
{
	char id;
	char *(*f)(va_list);
}print;

/* printf functions */
int _printf(const char *format, ...);
char *print_char(va_list arg_list);
char *print_string(va_list arg_list);
char *print_int(va_list arg_list);
char *print_binary(va_list arg_list);
char *rev_string(va_list arg_list);
char *rot13(va_list arg_list);

/* helper functions */
char *(*get_func(char ident))(va_list);
char *_strcpy(char *dest, char *src);
int _strlen(char *str);

/* buffer functions */
char *create_buffer(void);
void print_buffer(char *buffer, va_list arg_list, int len);
int check_buffer_overflow(char *buffer, int len);
#endif
