#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * int_to_str - integer to string
 *
 * @n: number to be converted.
 * @s: string to contain number.
 * @base: number base.
 */
void int_to_str(int n, char s[], int base)
{
	int i, sign = n;

	if (sign < 0)
		n = -n;

	i = 0;
	do {
	s[i++] = n % base + '0';
	} while ((n /= base) > 0);

	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	reverse(s);
}

/**
* reverse - reverse a string.
*
* @s: destinated string.
*/
void reverse(char s[])
{
	int i, j;
	char c;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
