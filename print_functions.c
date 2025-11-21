#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * flush_buffer - prints all stored values
 */
void flush_buffer(char *buffer, int *buffer_counter)
{
	write(1, buffer, *buffer_counter);
	*buffer_counter = 0;
}

/**
 * print_a_char - prints  only  a char
 * @args: arguments
 * Return: 1 on success
 */
int print_a_char(va_list *args, char *buffer, int *buffer_counter)
{
	char c = va_arg(*args, int);
	buffer[*buffer_counter] = c;
	(*buffer_counter)++;
	if (*buffer_counter == 1024)
	{
		flush_buffer(buffer, buffer_counter);
	}
	return (1);
}

/**
 * print_a_str - prints a char pointer
 * @args: arguments
 * Return: string length
 */
int print_a_str(va_list *args, char *buffer, int *buffer_counter)
{
	char *s = va_arg(*args, char*);
	int len = 0, i = 0;
	if (s == NULL)
	{
		while (i < 6)
		{
			buffer[*buffer_counter] = "(null)"[i];
			(*buffer_counter)++;
			i++;
			len++;
			if (*buffer_counter == 1024)
			{
				flush_buffer(buffer, buffer_counter);
			}
		}
	}
	while (*s)
	{
		buffer[*buffer_counter] = *s;
		(*buffer_counter)++;
		s++;
		len++;
		if (*buffer_counter == 1024)
		{
			flush_buffer(buffer, buffer_counter);
		}
	}
	return (len);
}

/**
 * print_special - prints a literal %
 * @args: arguments
 * Return: 1 on success
 */
int print_special(va_list *args, char *buffer, int *buffer_counter)
{
	(void)args;
	buffer[*buffer_counter] = '%';
	(*buffer_counter)++;
	if (*buffer_counter == 1024)
	{
		flush_buffer(buffer, buffer_counter);
	}
	return (1);
}

/**
 * print_an_int_or_decimal - prints an integer
 * @args: arguments
 * Return: int length
 */

int print_an_int_or_decimal(va_list *args, char *buffer, int *buffer_counter)
{
	int number = va_arg(*args, int);
	char digits[sizeof(int) * 8 + 2];
	int i = 0, j, len = 0;
	long n = number;

	if (number == 0)
	{
		buffer[*buffer_counter] = '0';
		(*buffer_counter)++;
		if (*buffer_counter == 1024)
		{
			flush_buffer(buffer, buffer_counter);
		}
		return (len);
	}

	if (n < 0)
	{
		buffer[*buffer_counter] = '-';
		(*buffer_counter)++;
		len++;
		n = -n;
		if (*buffer_counter == 1024)
		{
			flush_buffer(buffer, buffer_counter);
		}
	}

	while (n > 0)
	{
		digits[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		buffer[*buffer_counter] = digits[j];
		(*buffer_counter)++;
		len++;
		if (*buffer_counter == 1024)
		{
			flush_buffer(buffer, buffer_counter);
		}
	}
	return (len);
}

/**
 * print_binary - translates the numbers into binary
 * @args: arguments
 * Return: int length
 */

int print_binary(va_list *args, char *buffer, int *buffer_counter)
{
	unsigned int n = va_arg(*args, unsigned int);
	char digits[sizeof(unsigned int) *8];
	int i = 0, j, len = 0;

	if (n == 0)
	{
		buffer[*buffer_counter] = '0';
		(*buffer_counter)++;
		if (*buffer_counter == 1024)
		{
			flush_buffer(buffer, buffer_counter);
		}
		len++;
		return (len);
	}

	while (n > 0)
	{
		digits[i] = (n % 2) + '0';
		n = n / 2;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		buffer[*buffer_counter] = digits[j];
		(*buffer_counter)++;
		len++;
		if (*buffer_counter == 1024)
		{
			flush_buffer(buffer, buffer_counter);
		}
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
void print_unsigned_recursive(unsigned long n, unsigned int base, int uppercase, int *len, char *buffer, int *buffer_counter)
{
	const char *digits_l = "0123456789abcdef";
	const char *digits_u = "0123456789ABCDEF";
	const char *digits = uppercase ? digits_u : digits_l;
	char c;

	if (n >= base)
	{
		print_unsigned_recursive(n / base, base, uppercase, len, buffer, buffer_counter);
	}
	c = digits[n % base];
	buffer[*buffer_counter] = c;
	(*buffer_counter)++;
	(*len)++;
	if (*buffer_counter == 1024)
	{
		flush_buffer(buffer, buffer_counter);
	}
}

/**
 * print_unsigned_base - prints an unsigned base
 * @args: arguments
 * @base: base values
 * @uppercase: uppercases
 * Return: 0
 */
int print_unsigned_base(va_list *args, unsigned int base, int uppercase, char *buffer, int *buffer_counter)
{
	unsigned int n = va_arg(*args, unsigned int);
	int len = 0;

	print_unsigned_recursive(n, base, uppercase, &len, buffer, buffer_counter);
	return (len);
}

/**
 * print_unsigned_u - wrapper function for u
 * Return: print_unsigned_u
 */
int print_unsigned_u(va_list *args, char *buffer, int *buffer_counter)
{
	return print_unsigned_base(args, 10, 0, buffer, buffer_counter);
}

/**
 * print_unsigned_o - wrapper function for o
 * Return: print_unsigned_o
 */
int print_unsigned_o(va_list *args, char *buffer, int *buffer_counter)
{
	return print_unsigned_base(args, 8, 0, buffer, buffer_counter);
}

/**
 * print_unsigned_x - wrapper function for x
 * Return: print_unsigned_x
 */
int print_unsigned_x(va_list *args, char *buffer, int *buffer_counter)
{
	return print_unsigned_base(args, 16, 0, buffer, buffer_counter);
}

/**
 * print_unsigned_X - wrapper function for X
 * Return: print_unsigned_X
 */
int print_unsigned_X(va_list *args, char *buffer, int *buffer_counter)
{
	return print_unsigned_base(args, 16, 1, buffer, buffer_counter);
}

/**
 * print_string - prints a string with non priintable characters included
 * @args: arguments
 * Return:
 */

int print_string(va_list *args, char *buffer, int *buffer_counter)
{
	int len = 0, i = 0, first_digit, second_digit;
	unsigned char val;
	char first_char, second_char;
	char *s = va_arg(*args, char*);

	if (s == NULL)
	{
		while (i < 6)
		{
			buffer[*buffer_counter] = "(null)"[i];
			(*buffer_counter)++;
			i++;
			len++;
			if (*buffer_counter == 1024)
			{
				flush_buffer(buffer, buffer_counter);
			}
		}
	}
	while (*s)
	{
		if (*s >= 32 && *s <= 126)
		{
			buffer[*buffer_counter] = *s;
			(*buffer_counter)++;
			s++;
			len++;
			if (*buffer_counter == 1024)
			{
				flush_buffer(buffer, buffer_counter);
			}
		}
		else
		{
			buffer[*buffer_counter] = '\\';
			(*buffer_counter)++;
			buffer[*buffer_counter] = 'x';
			(*buffer_counter)++;
			val = (unsigned char)*s;
			first_digit = val / 16;
			second_digit = val % 16;
			if (first_digit < 10)
			{
				first_char = '0' + first_digit;
			}
			else
			{
				first_char = 'A' + (first_digit - 10);
			}
			buffer[*buffer_counter] = first_char;
			(*buffer_counter)++;
			if (second_digit < 10)
			{
				second_char = '0' + second_digit;
			}
			else
			{
				second_char = 'A' + (second_digit - 10);
			}
			buffer[*buffer_counter] = second_char;
			(*buffer_counter)++;
			s++;
			len += 4;
			if (*buffer_counter == 1024)
			{
				flush_buffer(buffer, buffer_counter);
			}
		}
	}
	flush_buffer(buffer, buffer_counter);
	return (len);
}

/**
 * print_address - prints the numeric address
 */

int print_address(va_list *args, char *buffer, int *buffer_counter)
{
	int i = 0, len = 0;
	unsigned long address;
	void *ptr = va_arg(*args, void*);

	if (ptr == NULL)
	{
		while (i < 5)
		{
			buffer[*buffer_counter] = "(nil)"[i];
			(*buffer_counter)++;
			i++;
			len++;
			if (*buffer_counter == 1024)
			{
				flush_buffer(buffer, buffer_counter);
			}
		}
		return(len);
	}
	buffer[*buffer_counter] = '0';
	(*buffer_counter)++;
	len++;
	buffer[*buffer_counter] = 'x';
	(*buffer_counter)++;
	len++;
	address = (unsigned long)ptr;
	print_unsigned_recursive(address, 16, 0, &len, buffer, buffer_counter);
	return(len);
}

