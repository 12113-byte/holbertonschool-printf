#include "main.h"
#include <limit.h>
#include <stdio.h>

/**
 * _strlen - returns the length of a string.
 * @s: parameter to be checked for size.
 * Return: length of a string
 */

int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		s++;
		length++;
	}
	return (length);
}

/**
 *
 *
 */

int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);

while (*format)
{
	if (*format == '%')
	{
		format++;
		if (*format == 's')
		{
			char *s = va_arg(args, char *);
			while (*format)
			{
				// our print function(*format)
				format++;
				counter++;
			}
		}
		else if (*format == 'c')
		{
			char c = (char)va_arg(args, int);
			// our print function(*format)
			counter++;
		}
		else
			print char literally
			counter++;
	}

format++;
}

va_end(args);
}

return (counter);
