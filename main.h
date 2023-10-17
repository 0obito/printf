#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);

int print_format(char ch, va_list args);
int print_character(int c);
int print_string(char *str);

#endif /* MAIN_H */
