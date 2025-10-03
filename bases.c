#include "main.h"

/**
 * print_binary - Converts an unsigned int to binary and prints it.
 * @n: The unsigned integer to convert.
 *
 * Return: The number of characters printed.
 */
int print_binary(unsigned int n)
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
 * print_base - Prints an unsigned int in base 8 or 16.
 * @n: The number.
 * @base: Base to print (8 or 16).
 * @uppercase: If non-zero, use 'A'-'F'; else 'a'-'f' for hex.
 *
 * Return: The number of characters printed.
 */
int print_base(unsigned int n, int base, int uppercase)
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
