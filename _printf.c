#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, j;
	char *str;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++; /* Move past the '%' */
			switch (format[i])
			{
				case 'c':
					_putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					str = va_arg(args, char *);
					if (str == NULL)
						str = "(null)";
					for (j = 0; str[j]; j++)
					{
						_putchar(str[j]);
						count++;
					}
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				default: /* Handle unknown specifiers */
					_putchar('%');
					_putchar(format[i]);
					count += 2;
					break;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
