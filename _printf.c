#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - produces output according to a format
 * @format: the string to be printed and which may contain directives
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	va_list ptr;

	if (format == NULL)
		return (-1);

	va_start(ptr, format);

	while (*(format + i))
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			count += write(1, &format[i + 1], 1);
			i += 2;
			continue;
		}
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			count += handle_conversion(&format[i], ptr);
			i += 2;
			continue;
		}
		else if (format[i] == '%' && format[i + 1] == '\0')
		{
			count = -1;
		}
		else
		{
			count += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(ptr);
	return (count);
}
