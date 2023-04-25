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
		{'r', conv_r},
		{'R', conv_R},
		{'\0', NULL}
	};
	int i;

	if (!format)
		return (-1);
	if ((format[0] == '%' && !format[1]) ||
			(format[0] == '%' && format[1] == ' ' && !format[2]))
		return (-1);
	va_start(conv, format);
	i = call_funcs(conversion, conv, format);
	va_end(conv);
	_putchar(-1);
	return (i);
}
/**
 * call_funcs - calls function for _printf
 * @conversion: struct list
 * @conv: va list
 * @format: what's to be printed
 * Return: int
 */
int call_funcs(conv_list *conversion,
		va_list conv, const char *format)
{
	int i, j, a, flag = 0, width = 0;
	char mod_flag = 0;

	for (i = 0, j = 0; format[j]; j++)
	{
		if (format[j] == '%' && flag != 2)
		{
			if (format[j - 1] != '%' && !format[j + 1])
				return (-1);
			for (a = 0, flag = 0; conversion[a].conv_spec; a++)
			{
				if (conversion[a].conv_spec == format[j + 1])
				{
					flag = 1;
					i += conversion[a].f(conv, mod_flag, width);
					mod_flag = 0;
				}
				if (_conv_flag(format, j))
					mod_flag = format[++j], a--;
				if (_length_mods(format, j))
					j++, a--;
				if (_field_width(format, j))
					width = (width * 10) + (format[++j] - '0'), a--;
			}
			if (flag != 1 && format[j + 1] != '%')
				i += _putchar(format[j--]), flag = 2;
			else if (flag != 1 && format[j + 1] == '%')
			{
				i += _putchar(format[j]);
			}
			j++;
		}
		else
		{
			i += _putchar(format[j]);
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

/**
 * _length_mods - checks for conversion specifiers
 * @s: string to check
 * @j: string index
 * Return: 1 if match, 0 is not
 */

int _length_mods(const char *s, int j)
{
	int h_flag = 0, hh_flag = 0, l_flag = 0;

	if (s[j + 1] == 'h')
	{
		if (s[j + 2] == 'h')
			hh_flag = 1;
		else
			h_flag = 1;
	}
	if (s[j + 1] == 'l')
	{
		l_flag = 1;
	}
	if (h_flag || hh_flag || l_flag)
		return (1);
	return (0);
}

/**
 * _field_width - checks for conversion specifiers
 * @s: string to check
 * @j: string index
 * Return: 1 if match, 0 is not
 */

int _field_width(const char *s, int j)
{
	if (s[j + 1] >= '0' && s[j + 1] <= '9')
		return (1);
	return (0);
}
