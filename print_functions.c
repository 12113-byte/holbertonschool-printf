#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_a_char - prints  only  a char
 */
void print_a_char(va_list *args)
{
	char c = va_arg(*args, int);
	write(1, &c, 1);
}

/**
 * print_a_char_ptr - prints a char pointer
 */
void print_a_str(va_list *args)
{
	char *s = va_arg(*args, char*);
	if (s == NULL)
    {
        s = "(null)";
    }
    while (*s)
	{
        write(1, s, 1);
        s++;
    }
}

/**
* print_special - prints a literal %
*/
void print_special(va_list *args)
{
    (void)args;
    write(1, "%", 1);
}

