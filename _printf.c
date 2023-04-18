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
	int i, count;

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
	i -= count;
	write(1, format, i);
	printf("\ni = %i\ncount = %i\n", i, count);
	return (i);
}
