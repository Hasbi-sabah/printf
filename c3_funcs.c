#include "main.h"

/**
 * conv_percent - prints %
 * @conv: arg
 * @buff: buff[1024]
 * @i: index
 * @f: flag characters for non-custom conversion specifiers
 * Return: length of write
 */

int conv_percent( NO_USE va_list conv, NO_USE char f, NO_USE int w)
{
	return (_putchar('%'));
}

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
	char *p = va_arg(conv, char *), s[] = "(null)";
	int z = 0;

	if (!p)
	{
		for (z = 0; s[z]; z++)
			_putchar(s[z]);
		return (z);
	}
	_strrev(p,_strlen(p));
	for (z = 0; p[z]; z++)
		_putchar(p[z]);
	return (z);
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
	int z = 0;

	if (!p)
	{
		for (z = 0; s[z]; z++)
			_putchar(s[z]);
		return (z);
	}
	_rot13(p);
	for (z = 0; p[z]; z++)
		_putchar(p[z]);
	return (z);
}
