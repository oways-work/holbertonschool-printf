#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h> /* For va_list, va_start, va_arg, va_end */
#include <unistd.h> /* For the write system call */
#include <stddef.h> /* For NULL */

/* The main _printf function prototype */
int _printf(const char *format, ...);

/* Helper function to print a single character */
int _putchar(char c);

#endif /* MAIN_H */
