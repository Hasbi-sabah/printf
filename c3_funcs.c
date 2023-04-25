#include "main.h"

/**
 * conv_r - prints %r
 * @conv: arg
 * @buff: buff[1024]
 * @i: index
 * @f: flag characters for non-custom conversion specifiers
 * Return: length of write
 */

int conv_r(va_list conv, NO_USE char f, NO_USE int w)
{
	char *p = va_arg(conv, char *), null[] = "(null)";
	int z = 0;

	if (!p)
	{
		for (z = 0; null[z]; z++)
			_putchar(null[z]);
		return (z);
	}
	for (z = _strlen(p); z >= 0; z--)
		_putchar(p[z]);
	return (_strlen(p));
}


/**
 * conv_R - prints %R
 * @conv: arg
 * @buff: buff[1024]
 * @i: index
 * @f: flag characters for non-custom conversion specifiers
 * Return: length of write
 */

int conv_R(va_list conv, NO_USE char f, NO_USE int w)
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
	}
	return (z);
}
