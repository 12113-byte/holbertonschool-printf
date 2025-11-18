#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - prints all arguments
 *
 * Return: counter
 */

typedef struct specifier {
    char specifier;
    void (*print_func)(va_list *);
} specifier_t;

specifier_t handlers[] = {
    { 'c', print_a_char },
    { 's', print_a_str },
    { '%', print_special },
    { 0, NULL }
};

int _printf(const char *format, ...)
{
	va_list args;
	int counter;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			char next = (*format + 1);
			int found = 0;
			for (counter = 0; handlers[counter].specifier != 0; counter++)
			{
				if (handlers[counter].specifier == next)
				{
					handlers[counter].print_func(&args);
					found = 1;
					break;
				}
			}
		if (found != 0)
		{
			write(1, "%", 1);
			write(1, &next, 1);
		}
		format += 2;
			else
			{
				write(1, format, 1);
				counter++;
			}
		}
	format++;
	}
	va_end(args);
	return (counter);
}

