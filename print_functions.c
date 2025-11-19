#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_a_char - prints  only  a char
 * @args: arguments
 * Return: 1 on success
 */
int print_a_char(va_list *args)
{
	char c = va_arg(*args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_a_str - prints a char pointer
 * @args: arguments
 * Return: string length
 */
int print_a_str(va_list *args)
{
	char *s = va_arg(*args, char*);
	int len = 0;

	if (s == NULL)
	{
		s = "(null)";
	}
	while (*s)
	{
		write(1, s, 1);
		s++;
		len++;
	}
	return (len);
}

/**
* print_special - prints a literal %
* @args: arguments
* Return: 1 on success
*/
int print_special(va_list *args)
{
	(void)args;
	write(1, "%", 1);
	return (1);
}

/**
 * print_a_decimal - prints a decimal
 * @args: arguments
 * Return: 1 on success
 */
void print_a_decimal(va_list *args)
{

int n

long num = n;

if (num < 0)
{
write(1, '-', 1);
num = -num;
}

if (num >= 10)
write(num / 10);

write char ((num % 10) + '0');
}
