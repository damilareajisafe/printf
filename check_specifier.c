#include "main"
#include <stdarg.h>
#include <stdio.h>
/**
 * check_specifier - checks if the char following the '%' match a specifier
 * @ele: the char to be checked
 * Return: a pointer to the print function that matches the specifier or NULL
 * if it fails
 */

int (*check_specifier(const char *ele))(va_list)
{
	int i;
	specifier_t spec[] = {
		{"d", print_int},
		{"c", print_char},
		{"i", print_int},
		{"s", print_string},
		{NULL, NULL},
	};
	for (i = 0; spec[i].sp != NULL; i++)
	{
		if (*(spec[i].sp) == *ele)
			return (spec[i].f);
	}

	return (NULL);
}
