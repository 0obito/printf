#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 * print_format - function that takes action
 * when the character '%' is detected, in order
 * to check for format specifiers.
 *
 * @ch: character that comes after '%'.
 * @args: arguments list.
 *
 * Return: number of characters printed.
 */
int print_format(char ch, va_list args)
{
	int count = 0;

	if (ch == 'c')
		count = print_character(va_arg(args, int));
	if (ch == 's')
		count = print_string(va_arg(args, char *));
	if (ch == '%')
		count = write(1, "%", 1);
	if (ch == 'd')
		count = print_integer(va_arg(args, int), 10);
	if (ch == 'i')
		count = print_integer(va_arg(args, int), 10);
	if (ch == 'b')
		count = print_binary(va_arg(args, int), 0);

	return (count);
}

/**
 * print_character - prints a character.
 *
 * @c: character to be printed.
 *
 * Return: number of characters printed.
 */
int print_character(int c)
{
	int i;

	i = write(1, &c, 1);
	return (i);
}

/**
 * print_string - prints a string.
 *
 * @string: string to be printed.
 *
 * Return: number of characters printed.
 */
int print_string(char *string)
{
	int count = 0;

	while (*string)
	{
		count = count + write(1, string, 1);
		string++;
	}

	return (count);
}

/**
 * print_integer - prints an integer
 *
 * @num: the number to be printed.
 *
 * Return: number of digits printed.
 */
int print_integer(int num, int base)
{
	int count = 0, len;
	char numStr[12];

	int_to_str(num, numStr, base);
	len = strlen(numStr);
	write(1, numStr, len);
	count = count + len;

	return (count);
}

/**
 * print_binary - prints a decimal in binary.
 *
 * @numb: the integer to be printed in binary.
 *
 * Return: number of digits printed.
 */
int print_binary(unsigned int numb, int count)
{
	if (numb > 1)
		count = print_binary(numb / 2, count);

	print_integer(numb % 2, 10);

	return (count + 1);
}
