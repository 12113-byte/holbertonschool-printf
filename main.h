#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int _strlen(char *s);
void print_a_str(va_list *args);
void print_special(va_list *args);
void print_a_char(va_list *args);

typedef struct specifier {
    char specifier;
    void (*print_func)(va_list *);
} specifier_t;

#endif

