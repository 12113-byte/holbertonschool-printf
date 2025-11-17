#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);

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
 * print_a_char - prints  only  a char
 */
void print_a_char(va_list *args)
{
	char c = va_arg(*args, int);
	write(1, c, _strlen(c));
}

/**
 * print_an_int - prints only  ints
 */
//void print_an_int(va_list args)
//{
//	int value = va_arg(args, int);
//	write(1, value, _strlen(value));
//}

/**
 * print_a_float - prints a  float
 */
//void print_a_float(va_list args)
//{
//	double value = va_arg(args, double);
//	write(1, value, _strlen(value));
//}

/**
 * print_a_char_ptr - prints a char pointer
 */
void print_a_char_ptr(va_list *args)
{
	va_arg(args, char  *);
	if (s == NULL)
    {
        s = "(null)";
    }
    while (*s)
	{
        write(1, *s, 1);
        *s++;
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
#endif

