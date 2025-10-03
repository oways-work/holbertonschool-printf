#include "main.h"

static int handle_specifier(char specifier, va_list args);
static int print_int(va_list args);
static int print_unsigned_rec(unsigned int n);
static int print_binary(unsigned int n) __attribute__((unused));
static int print_unsigned(va_list args);                 
static int print_base(unsigned int n, int base, int uppercase);

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
			break;
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

/**
 * print_unsigned_rec - Prints an unsigned integer recursively.
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
 * print_int - Prints a signed integer.
 * @args: The va_list containing the integer argument.
 *
 * Return: The number of characters printed.
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

/**
 * print_binary - Converts an unsigned int to binary and prints it.
 * @n: The unsigned integer to convert.
 *
 * Return: The number of characters printed.
 */
static int print_binary(unsigned int n)
{
	int count = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	if (n / 2)
		count += print_binary(n / 2);

	count += _putchar((n % 2) + '0');

	return (count);
}

/**
 * print_unsigned - Prints an unsigned decimal integer (%u).
 * @args: The va_list containing the unsigned int.
 *
 * Return: The number of characters printed.
 */
static int print_unsigned(va_list args)
{
	unsigned int u = va_arg(args, unsigned int);


	return (print_unsigned_rec(u));
}
/**
 * print_base - Prints an unsigned int in a given base (8 or 16 for this task).
 * @n: The number.
 * @base: Base to print (8 or 16).
 * @uppercase: If non-zero, use 'A'-'F'; else 'a'-'f' for hex.
 *
 * Return: The number of characters printed.
 */
static int print_base(unsigned int n, int base, int uppercase)
{
	int count = 0;
	char digit;

	if (base != 8 && base != 16)
		return (0);

	if (n == 0)
		return (_putchar('0'));

	if (n / (unsigned int)base)
		count += print_base(n / (unsigned int)base, base, uppercase);

	n %= (unsigned int)base;

	if (n < 10)
		digit = (char)('0' + n);
	else
		digit = (char)((uppercase ? 'A' : 'a') + (n - 10));

	count += _putchar(digit);
	return (count);
}
