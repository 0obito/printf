#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - a printf like function.
 *
 * @format: the string to be printed,
 * including the format specifiers.
 *
 * Return: the number of characters printed.
 */

int _printf(const char *format, ...)
{
	int sum = 0;
	va_list args;

	if (format == NULL)
	return (-1);

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			sum += print_format(*format, args);
		}
		else
			sum += write(1, format, 1);

		format++;
	}

	va_end(args);
	return (sum);
}
