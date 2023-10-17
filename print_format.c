#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
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
	else if (ch == 's')
		count = print_string(va_arg(args, char *));
	else
		count = write(1, &ch, 1);

	return count;
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

	return count;
}
