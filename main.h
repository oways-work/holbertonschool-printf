#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h> /* For va_list, va_start, va_arg, va_end */
#include <unistd.h> /* For the write system call */
#include <stddef.h> /* For NULL */

/* The main _printf function prototype */
int _printf(const char *format, ...);

/* Helper function to print a single character */
int _putchar(char c);

/* Prints a signed integer */
int print_int(va_list args);

/* Prints an unsigned integer in base 10 */
int print_unsigned_rec(unsigned int n);

/* Prints an unsigned integer using decimal recursion */
int print_unsigned(va_list args);

/* Prints an unsigned integer in binary */
int print_binary(unsigned int n);

/* Prints an unsigned integer in base 8 or 16 */
int print_base(unsigned int n, int base, int uppercase);

#endif /* MAIN_H */
