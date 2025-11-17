#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - prints all arguments
 *
 * Return: counter
 */

int _printf(const char *format, ...)
{
	va_list args;
	int counter = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				write(1, "%", 1);
				counter++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char*);
				if (str == NULL)
				{
					write(1, "(null)", 6);
					counter += 6;
				}
				while (*str)
				{
					write(1, str, 1);
					str++;
					counter++;
				}
			}
			else if (*format == 'c')
			{
				int c = (char)va_arg(args, int);
				write(1, &c, 1);
				counter++;
			}
			else
			{
				write(1, format, 1);
				counter++;
			}
		}
		else
		{
			write(1, format, 1);
			counter++;
		}
	format++;
	}
	va_end(args);
	return (counter);i
}

