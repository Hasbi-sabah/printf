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
	conv_list conversion[] = {
		{'c', conv_c},
		{'s', conv_s},
		{'i', conv_i_d},
		{'d', conv_i_d},
		{'b', conv_b},
		{'u', conv_u},
		{'o', conv_o},
		{'x', conv_x},
		{'X', conv_X},
		{'S', conv_S},
		{'p', conv_p},
		{'\0', NULL}
	};
	int i;
	char buff[1024];

	if (!format)
		return (-1);
	va_start(conv, format);
	i = call_funcs(conversion, conv, format, buff);
	va_end(conv);
	if (*buff)
		write(1, buff, i);
	return (i);
}
/**
 * call_funcs - calls function for _printf
 * @conversion: struct list
 * @conv: va list
 * @format: what's to be printed
 * @buff: buffer
 * Return: int
 */
int call_funcs(conv_list *conversion,
		va_list conv, const char *format, char *buff)
{
	int i, j, a, flag = 0;
	char mod_flag = 0;

	for (i = 0, j = 0; format[j]; j++)
	{
		if (format[j] == '%' && flag != 2)
		{
			for (a = 0, flag = 0; conversion[a].conv_spec; a++)
			{
				if (format[j + 1] == '%')
				{
					buff[i++] = '%', flag = 1;
					break;
				}
				if (conversion[a].conv_spec == format[j + 1])
				{
					flag = 1;
					i = conversion[a].f(conv, buff, i, mod_flag);
					mod_flag = 0;
				}
				if (_conv_flag(format, j))
				{
					mod_flag = format[++j];
					a--;
				}
			}
			if (flag != 1)
			{
				buff[i++] = format[--j];
				j--, flag = 2;
			}
			j++;
		}
		else
		{
			buff[i++] = format[j];
			flag = 0;
		}
	}
	return (i);
}
/**
 * _conv_flag - checks for conversion specifiers
 * @s: string to check
 * @j: string index
 * Return: 1 if match, 0 is not
 */

int _conv_flag(const char *s, int j)
{
	if (s[j + 1] == '#' || s[j + 1] == '+' ||
			s[j + 1] == ' ')
		return (1);
	return (0);
}


