#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * handle_conversion - checks if the specifier is valid or otherwise and prints
 * the correct output
 * @c: pointer to any '%' found in the string to be printed
 * @ptr: argument list pointer
 * Return: number of characters printed
 */
int handle_conversion(const char *c, va_list ptr)
{
	int count = 0;
	int (*p)(va_list);

	p = check_specifier(c + 1);
	if (p == NULL)
	{
		count += write(1, c, 1);
		count += write(1, c + 1, 1);
	}
	else
	{
		count += p(ptr)
	}
	return (count);
}
