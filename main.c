#include "main.h"
#include <limit.h>
#include <stdio.h>

/**
 *
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
			char *str = va_arg(args, char*);
			while (*str)
			{
				// our print function(*str)
				str++;
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
			//our print function(*format);
			counter++;
	}

format++;
}

va_end(args);
}

return (counter);
