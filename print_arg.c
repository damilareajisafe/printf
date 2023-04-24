#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * print_int - prints an integer
 * @ptr: pointer to the list of arguments
 * Return: number of characters printed
 */

int print_int(va_list ptr)
{
	int num = va_arg(ptr, int);
	int count = 0;
	char buffer[15];
	int sign = num, i = 0, len;

	if (ptr == NULL)
		return (0);
	if (sign < 0)
		num = -num;

	while (num > 0)
	{
		buffer[i] = num % 10 + '0';
		num = num / 10;
		i++;
	}

	if (sign < 0)
		buffer[i++] = '-';

	buffer[i] = '\0';
	len = strlen(buffer);
	for (i = len - 1; i >= 0; i--)
	{
		count += write(1, &buffer[i], 1);
	}
	return (count);
}

/**
 * print_char - prints a character
 * @ptr: pointer to the list of arguments
 * Return: number of characters printed
 */
int print_char(va_list ptr)
{
	int count = 0;
	char c = va_arg(ptr, int);

	if (ptr == NULL)
		return (0);

	count += write(1, &c, 1);
	return (count);
}

/**
 * print_string - prints a string
 * @ptr: pointer to the list of arguments
 * Return: number of characters printed
 */

int print_string(va_list ptr)
{
	int count = 0;
	int i = 0;
	char *p = va_arg(ptr, char*);

	if (ptr == NULL || p == NULL)
		return (0);

	while (p[i])
	{
		count += write(1, &p[i], 1);
		i++;
	}

	return (count);
}
