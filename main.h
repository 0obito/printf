#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);

int print_format(char ch, va_list args);
int print_character(int c);
int print_string(char *str);
int print_integer(int num, int base);
int print_binary(unsigned int numb, int count);

void int_to_str(int n, char s[], int base);
void reverse(char s[]);

int print_unsigned(unsigned int num);
int print_octal(unsigned int num);
int print_hex(unsigned int num, int uppercase);


#endif /* MAIN_H */
