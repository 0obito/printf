#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_unsigned - print an unsigned integer.
 *
 * @num: the unsigned integer.
 *
 * Return: the number of characters printed.
 */
int print_unsigned(unsigned int num)
{
	int count = 0, len;
	char numStr[11];

	int_to_str(num, numStr, 10);
	len = strlen(numStr);
	write(1, numStr, len);
	count = count + len;

	return (count);
}

/**
 * print_octal - print an unsigned integer in octal.
 *
 * @num: the unsigned integer.
 *
 * Return: the number of characters printed.
 */
int print_octal(unsigned int num)
{
        int count;

        count = print_integer(num, 8);

	return (count);
}

/**
 * print_hex - print an unsigned integer in hexadecimal.
 * @num: the unsigned integer.
 *
 * @uppercase: flag to print in uppercase (X) or lowercase (x).
 *
 * Return: the number of characters printed.
 */
int print_hex(unsigned int numb, int uppercase)
{
    char buffer[19];
    int count = 0;
    int i, j;
    char hex_digits[] = "0123456789abcdef";

    if (uppercase)
    {
        hex_digits[10] = 'A';
        hex_digits[11] = 'B';
        hex_digits[12] = 'C';
        hex_digits[13] = 'D';
        hex_digits[14] = 'E';
        hex_digits[15] = 'F';
    }

    if (numb == 0)
    {
        buffer[0] = '0';
        count = 1;
    }
    else
    {
        i = 0;
        while (numb > 0)
	{
            buffer[i] = hex_digits[numb % 16];
            numb /= 16;
            i++;
        }
        count = i;
    }

    for (j = count - 1; j >= 0; j--)
        write(1, &buffer[j], 1);

    return count;
}
