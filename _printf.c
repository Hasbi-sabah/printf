#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 *
 * @format: what's to be printed
 *
 * Return: int
 */

int _printf(const char *format, ...)
{
	va_list conv;
	int i, j, k, count;
	char *p;

	for (i = 0, count = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					count++;
					break;
				case 's':
					count++;
					break;
			}
		}
	}
	va_start(conv, format);
	for (j = 0; j < count; j++)
	{
		p = va_arg(conv, char *);
		for (k = 0; p[k]; k++)
			i++;
		i--;
	}
	va_end(conv);
	i -= count;
	va_start(conv, format);
	for (j = 0; format[j]; j++)
	{
		if (format[j] == '%' &&
				(format[j + 1] == 'c' || format[j + 1] == 's'))
		{
			p = va_arg(conv, char *);
			for (k = 0; p[k]; k++)
				;
			write(1, p, k);
			j++;
		}
		else
		{
			write(1, &format[j], 1);
		}
	}
	va_end(conv);
	return (i);
}
