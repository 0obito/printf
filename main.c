#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int main(void)
{
	int a;

	a = _printf("This is a binary number for %d: %b", 11, 11);
	printf("\n%d", a);
	return (0);
}
