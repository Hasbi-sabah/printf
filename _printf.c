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
	int i, j, k;
	char *p, c;
	
	va_start(conv, format);
	for (i = 0, j = 0, k = 0; format[j]; j++)
	{
		if (_conv_flag(format, j))
		{
			if (format[j + 1] == 'c')
			{
				c = va_arg(conv, int);
				write(1, &c, 1);
				k = 1;
			}
			else
			{
				p = va_arg(conv, char *);
				k = _strlen(p);
				write(1, p, k);
			}
			j++;
			i += k;
		}
		else
		{
			write(1, &format[j], 1);
			i++;
		}
	}
	va_end(conv);
	printf("%i\n", i);
	return (i);
}

/**
 * _strlen - swaps the values of two integers.
 *@s: string
 * Return: length
 */

int _strlen(const char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;
	return (i);
}

int _conv_flag(const char *s, int j)
{
	if ((s[j] == '%') && (s[j + 1] == 'c' ||
				s[j + 1] == 's' ||
				s[j + 1] == 'd' ||
				s[j + 1] == 'i'))
		return (1);
	return (0);
}
