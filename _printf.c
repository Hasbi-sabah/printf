#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: what's to be printed
 *
 * Return: int
 */

int _printf(const char *format, ...)
{
	va_list conv;
	struct conversion conversion[] = {
		{'c', conv_c},
		{'s', conv_s},
		{'i', conv_i_d},
		{'d', conv_i_d},
		{'b', conv_b},
		{'u', conv_u},
		{'o', conv_o},
		{'x', conv_x},
		{'X', conv_X}
	};
	int i, j, k, a, flag;

	va_start(conv, format);
	for (i = 0, j = 0, k = 0; format[j]; j++)
	{
		if (format[j] == '%')
		{
			for (a = 0, flag = 0; conversion[a].conv_spec; a++)
			{
				if (conversion[a].conv_spec == format[j + 1])
				{
					flag = 1;
					k = conversion[a].f(conv);
				}
			}
			if (flag != 1)
			{
				write(1, &format[j], 1);
				j--;
				k++;
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
	printf("%d\n", i);
	return (i);
}

/**
 * _strlen - return length of s
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

/**
 * _conv_flag - checks for conversion specifiers
 * @s: string
 * @j: string index
 * Return: 1 if match, 0 is not
 */

int _conv_flag(const char *s, int j)
{
	if ((s[j] == '%') && (s[j + 1] == 'c' ||
				s[j + 1] == 's' ||
				s[j + 1] == 'd' ||
				s[j + 1] == 'i'))
		return (1);
	return (0);
}
