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
		{'X', conv_X},
		{'S', conv_S},
		{'p', conv_p}
	};
	int i, j, a, flag;
	char buff[1024], mod_flag = 0;

	va_start(conv, format);
	for (i = 0, j = 0; format[j]; j++)
	{
		if (format[j] == '%' && flag != 2)
		{
			for (a = 0, flag = 0; conversion[a].conv_spec; a++)
			{
				if (conversion[a].conv_spec == format[j + 1])
				{
					flag = 1;
					i = conversion[a].f(conv, buff, i, mod_flag);
					mod_flag = 0;
				}
				if (_conv_flag(format, j))
				{
					mod_flag = format[j + 1];
					j++;
					a--;
				}
			}
			if (flag != 1)
			{
				j -= 2;
				buff[i] = format[j];
				flag = 2;
			}
			j++;
		}
		else
		{
			buff[i] = format[j];
			i++;
			flag = 0;
		}
	}
	va_end(conv);
	buff[i] = '\0';
	write(1, buff, i);
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
	if (s[j + 1] == '#'|| s[j + 1] == '+' ||
			s[j + 1] == ' ')
		return (1);
	return (0);
}

/**
 * _strcpy - copies the string pointed to by src to dest
 *
 *@src: string
 *@dest: buffer
 * Return: string
 */

int _strcpy(char *dest, char *src, int i)
{
	int j;

	for (j = 0; src[j] != '\0'; j++, i++)
		dest[i] = src[j];
	return (i);
}

/**
 * _strrev - copies and reverses a string
 *
 *@src: string
 *@dest: buffer
 * Return: string
 */

int _strrev(char *dest, char *src, int i, int j)
{
	for (; j > 0; j--, i++)
		dest[i] = src[j - 1];
	return (i);
}
/**
 * _strcat - concatenates two strings
 *
 *@src: first string
 *@dest: second string
 *
 *Return: dest string
 */

void _strcat(char *dest, char *src, int i)
{
	int j, k, l;
	
	j = _strlen(dest);
	k = _strlen(src);
	for (l = j - 1; l > i; l--)
		dest[l + k - 1] = dest[l];
	for (l = 0; l < k; l++)
		dest[i + l] = src[l];
}
