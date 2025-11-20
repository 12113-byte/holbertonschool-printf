#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _printf(const char *format, ...);
int _strlen(char *s);
int print_a_str(va_list *args);
int print_special(va_list *args);
int print_a_char(va_list *args);
int print_an_int_or_decimal(va_list *args);
int print_binary(va_list *args);
int print_unsigned_base(va_list *args, unsigned int base, int uppercase);
void print_unsigned_recursive(unsigned int n, unsigned int base, int uppercase);

typedef struct specifier
{
	char specifier;
	int (*print_func)(va_list *);
} specifier_t;

#endif

