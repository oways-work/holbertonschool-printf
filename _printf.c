#include "main.h"

static int handle_specifier(char specifier, va_list args);


/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte).
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
		case 'b':
			count += print_binary(va_arg(args, unsigned int));
			break;
		case 'u':
			count += print_unsigned(args);
			break;
		case 'o':
			count += print_base(va_arg(args, unsigned int), 8, 0);
			break;
		case 'x':
			count += print_base(va_arg(args, unsigned int), 16, 0);
			brek;
		case 'X':
			count += print_base(va_arg(args, unsigned int), 16, 1);
			break;
		default:
			count += _putchar('%');
			count += _putchar(specifier);
			break;
	}
	return (count);
}
