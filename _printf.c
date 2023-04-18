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
	char *p;
	
	va_start(conv, format);
	for (i = 0, j = 0; format[j]; j++)
	{
		if (format[j] == '%' &&
				(format[j + 1] == 'c' || format[j + 1] == 's'))
		{
			p = va_arg(conv, char *);
			k = _strlen(p);
			write(1, p, k);
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
/*
void _case_count(const char *s, int *i, int *count)
{
	*i = 0, *count = 0;
	for (; s[*i]; (*i)++)
	{
		if ((s[*i] == '%') && (s[*i + 1] != 'c' ||
					s[*i + 1] != 's' ||
					s[*i + 1] != 'd' ||
					s[*i + 1] != 'i'))
			(*count)++;
	}

}
*/
