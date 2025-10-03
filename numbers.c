#include "main.h"

/**
 * print_unsigned_rec - Prints an unsigned integer (base 10) recursively.
 * @n: The unsigned integer to print.
 *
 * Return: The number of characters printed.
 */
int print_unsigned_rec(unsigned int n)
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
int print_int(va_list args)
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
 * print_unsigned - Prints an unsigned decimal integer (%u).
 * @args: The va_list containing the unsigned int.
 *
 * Return: The number of characters printed.
 */
int print_unsigned(va_list args)
{
	unsigned int u = va_arg(args, unsigned int);

	return (print_unsigned_rec(u));
}

