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
 * print_an_int - prints an integer
 * @args: arguments
 * Return: int length
 */

int print_an_int_or_decimal(va_list *args)
{
	int number = va_arg(*args, int);
	char digits[12];
	int i = 0, j, len = 0;
	long n = number;

	if (number == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	if (n < 0)
	{
		write(1, "-", 1);
		len++;
		n = -n;
	}

	while (n > 0)
	{
		digits[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		write(1, &digits[j], 1);
		len++;
	}
	return (len);
}

/**
 * print_binary - translates the numbers into binary
 * @args: arguments
 * Return: int length
 */

int print_binary(va_list *args)
{
	unsigned int n = va_arg(*args, unsigned int);
	char digits[32];
	int i = 0, j, len = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (n > 0)
	{
		digits[i] = (n % 2) + '0';
		n = n / 2;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		write(1, &digits[j], 1);
		len++;
	}
	return (len);
}

/**
 * print_unsigned_base - prints an unsigned base
 * @n: counter
 * @base: base value
 * @uppercase: uppercase
 * Return: void
 */
void print_unsigned_recursive(unsigned int n, unsigned int base, int uppercase)
{
    	const char *digits_l = "0123456789abcdef";
    	const char *digits_u = "0123456789ABCDEF";
    	const char *digits = uppercase ? digits_u : digits_l;

    	if (n >= base)
        	print_unsigned_recursive(n / base, base, uppercase);

    	char c = digits[n % base];
    	write(1, &c, 1);
}

/**
 * print_unsigned_base - prints an unsigned base
 * @args: arguments
 * @base: base values
 * @uppercase: uppercases
 * Return: 0
 */
int print_unsigned_base(va_list *args, unsigned int base, int uppercase)
{
    	unsigned int n = va_arg(*args, unsigned int);

    	print_unsigned_recursive(n, base, uppercase);

    	return 0;
}

/**
 * print_unsigned_u - wrapper function for u
 * Return: print_unsigned_u
 */
int print_unsigned_u(va_list args)
{
    return print_unsigned_base(args, 10, 0);
}

/**
 * print_unsigned_o - wrapper function for o
 * Return: print_unsigned_o
 */
int print_unsigned_o(va_list args)
{
    return print_unsigned_base(args, 8, 0);
}

/**
 * print_unsigned_x - wrapper function for x
 * Return: print_unsigned_x
 */
int print_unsigned_x(va_list args)
{
    return print_unsigned_base(args, 16, 0);
}

/**
 * print_unsigned_X - wrapper function for X
 * Return: print_unsigned_X
 */
int print_unsigned_X(va_list args)
{
    return print_unsigned_base(args, 16, 1);
}

