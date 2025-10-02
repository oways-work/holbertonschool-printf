#include "main.h"

static int handle_specifier(char specifier, va_list args);
static int print_int(va_list args);
static int print_unsigned_rec(unsigned int n);

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte).
 * On error, -1 is returned.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);

			count += handle_specifier(format[i], args);
		}
		else
		{
			count += _putchar(format[i]);
		}
	}
	va_end(args);
	return (count);
}

/**
 * handle_specifier - Prints an argument based on a format specifier.
 * @specifier: The character that specifies the format.
 * @args: The va_list containing the arguments.
 *
 * Return: The number of characters printed.
 */
static int handle_specifier(char specifier, va_list args)
{
	int count = 0;
	char *str;

	switch (specifier)
	{
		case 'c':
			count += _putchar(va_arg(args, int));
			break;
		case 's':
			str = va_arg(args, char *);
			if (str == NULL)
				str = "(null)";
			while (*str)
				count += _putchar(*str++);
			break;
		case '%':
			count += _putchar('%');
			break;
		case 'd':
                case 'i':
                        count += print_int(args);
                        break; 
		default:
			count += _putchar('%');
			count += _putchar(specifier);
			break;
	}
	return (count);
}

/**
 * print_unsigned_rec - Prints an unsigned integer recursively in base 10.
 * @n: The unsigned integer to print.
 *
 * Return: The number of characters printed.
 */

static int print_unsigned_rec(unsigned int n)
{
    int count = 0;

    if (n / 10)
        count += print_unsigned_rec(n / 10);

    count += _putchar((n % 10) + '0');
    return (count);
}

/**
 * print_int - Prints a signed integer for %d and %i.
 * @args: The va_list containing the integer argument.
 *
 * Return: The number of characters printed (including '-' if negative).
 */

static int print_int(va_list args)
{
    int n = va_arg(args, int);
    unsigned int u;
    int count = 0;

    if (n < 0)
    {
        count += _putchar('-');
        u = (unsigned int)(-(n + 1)) + 1;
    }
    else
    {
        u = (unsigned int)n;
    }

    count += print_unsigned_rec(u);
    return (count);
}
