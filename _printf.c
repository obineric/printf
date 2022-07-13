#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _putchar- function to print a single character
 * @c: character input
 * Return: integer
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _printf - program to print characters using formatters
 * @format: compulsory string input
 * Return: number of character in string
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int i;
	int count = 0;

	va_start(ap, format);

	for (i = 0; format && format[i] != '\0'; i++)
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			char var;

			var = va_arg(ap, int);
			_putchar(var);
			count++;
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			int j = 0;

			char *ptr = va_arg(ap, char *);

			while (ptr[j] != '\0')
			{
				j++;
			}
			write(1, &ptr[0], j);
			count = count + j;
			i++;
		}
		else
		{
			continue;
		}

	va_end(ap);
	_putchar('\n');
	return (count);
}
