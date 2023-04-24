#include <stdarg.h>
#ifndef MAIN_H
#define MAIN_H
/**
 * struct specifiers - Struct specifiers
 *
 * @sp: the specifier
 * @f: the function associated with @sp
 */

typedef struct specifiers
{
    const char *sp;
    int (*f)(va_list);
} specifier_t;

int _printf(const char *format, ...);
int print_int(va_list);
int print_char(va_list);
int print_string(va_list);
int (*check_specifier(const char*))(va_list);
int handle_conversion(const char*, va_list);

#endif
