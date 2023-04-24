#include "main.h"

/**
 * conv_percent - prints %
 * @conv: arg
 * @buff: buff[1024]
 * @i: index
 * @f: flag characters for non-custom conversion specifiers
 * Return: length of write
 */

int conv_percent(__attribute__ ((unused)) va_list conv,
		__attribute__ ((unused)) char *buff,
		__attribute__ ((unused)) int i,
		__attribute__ ((unused)) char f)
{
	buff[i++] = '%';
	return (i);
}

/**
 * conv_r - prints %r
 * @conv: arg
 * @buff: buff[1024]
 * @i: index
 * @f: flag characters for non-custom conversion specifiers
 * Return: length of write
 */
int conv_r(va_list conv, char *buff, int i,
		__attribute__ ((unused)) char f)
{
	char *p = va_arg(conv, char *), s[] = "(null)";

	if (!p)
	{
		i = _strcpy(buff, s, i);
		return (i);
	}
	i = _strrev(buff, p, i, _strlen(p));
	return (i);
}


/**
 * conv_R - prints %R
 * @conv: arg
 * @buff: buff[1024]
 * @i: index
 * @f: flag characters for non-custom conversion specifiers
 * Return: length of write
 */
int conv_R(va_list conv, char *buff, int i,
		__attribute__ ((unused)) char f)
{
	char *p = va_arg(conv, char *), s[] = "(null)";

	if (!p)
	{
		i = _strcpy(buff, s, i);
		return (i);
	}
	i = rot13(buff ,p, i);
	return (i);
}
