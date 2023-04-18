#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
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
	int i, j, k, a, b, l;
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
			else if (format[j + 1] == 's')
			{
				p = va_arg(conv, char *);
				k = _strlen(p);
				write(1, p, k);
			}
			else
			{
				a = va_arg(conv, int);
				if (a == 0)
					write(1, "0", 1);
				else
				{
					if (a < 0)
					{
						a = -a;
						write(1, "-", 1);
					}
					for (l = 0, b = a; b > 0; l++)
						b /= 10;
					k = l;
					p = malloc(sizeof(int)*(l+1));
					for (l--; a > 0; l--)
					{
						p[l] = a % 10 + '0';
						a /= 10;
					}
					write(1, p, k);
				}
			}
			j++;
			i += k;
			/*
			   if (format[j + 1] == 'i' || (format[j + 1] == 'd'))
			  */
		}
		else
		{
			write(1, &format[j], 1);
			i++;
		}
	}
	va_end(conv);
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
