#include "main.h"

/**
 * conv_r - prints %r
 * @conv: arg
 * @f: flag characters for non-custom conversion specifiers
 * @w: field width
 * Return: length of write
 */

int conv_r(va_list conv, __attribute__ ((unused)) char f,
		__attribute__ ((unused)) int w)
{
	char *p = va_arg(conv, char *), null[] = "(null)";
	int i, z = 0;

	if (!p)
	{
		for (z = 0; null[z]; z++)
			_putchar(null[z]);
		return (z);
	}
	for (i = _strlen(p) - 1; _strlen(p) && i >= 0; i--, z++)
		_putchar(p[i]);
	return (z);
}


/**
 * conv_R - prints %R
 * @conv: arg
 * @f: flag characters for non-custom conversion specifiers
 * @w: field width
 * Return: length of write
 */

int conv_R(va_list conv, __attribute__ ((unused)) char f,
		__attribute__ ((unused)) int w)
{
	char *p = va_arg(conv, char *), s[] = "(null)";
	int i, j, z = 0;
	char og[] = "azertyuiopqsdfghjklmwxcvbnAZERTYUIOPQSDFGHJKLMWXCVBN",
	     rot[] = "nmreglhvbcdfqstuwxyzjkpioaNMREGLHVBCDFQSTUWXYZJKPIOA";

	if (!p)
	{
		for (z = 0; s[z]; z++)
			_putchar(s[z]);
		return (z);
	}
	for (i = 0; i < _strlen(p); i++)
	{
		if ((p[i] >= 'a' && p[i] <= 'z') || (p[i] >= 'A' && p[i] <= 'Z'))
		{
			for (j = 0; og[j] != '\0'; j++)
			{
				if (p[i] == og[j])
				{
					_putchar(rot[j]);
					z++;
					break;
				}
			}
		}
		else
		{
			_putchar(p[i]);
			z++;
		}
	}
	return (z);
}
