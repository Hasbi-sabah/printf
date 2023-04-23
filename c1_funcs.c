#include "main.h"

/**
 * conv_c - prints %c
 * @conv: arg
 * @buff: buff[1024]
 * @i: index
 * @f: flag characters for non-custom conversion specifiers
 * Return: length of write
 */

int conv_c(va_list conv, char *buff, int i, __attribute__ ((unused)) char f)
{
	char c = va_arg(conv, int);

	buff[i++] = c;
	return (i);
}

/**
 * conv_s - prints %s
 * @conv: arg
 * @buff: buff[1024]
 * @i: index
 * @f: flag characters for non-custom conversion specifiers
 * Return: length of write
 */

int conv_s(va_list conv, char *buff, int i, __attribute__ ((unused)) char f)
{
	char *p = va_arg(conv, char *), s[] = "(null)";

	if (!p)
	{
		i = _strcpy(buff, s, i);
		return (i);
	}
	i = _strcpy(buff, p, i);
	return (i);
}

/**
 * conv_i_d - prints %i and %d
 * @conv: arg
 * @buff: buff[1024]
 * @i: index
 * @f: flag characters for non-custom conversion specifiers
 * Return: length of write
 */

int conv_i_d(va_list conv, char *buff, int i, char f)
{
	int j = va_arg(conv, int), k, flag = 0;
	char temp[25], min[] = "-2147483648";

	if ((f == ' ' || f == '+') && j >= 0)
		buff[i++] = f;
	if (j == -2147483648)
	{
		i = _strcpy(buff, min, i);
		return (i);
	}
	if (j == 0)
		buff[i++] = '0';
	if (j < 0)
	{
		j = 0 - j;
		flag = 1;
	}
	for (k = 0; j > 0; k++)
	{
		temp[k] = j % 10 + '0';
		j /= 10;
	}
	if (flag)
		temp[k++] = '-';
	i = _strrev(buff, temp, i, k);
	return (i);
}
/**
 * conv_b - prints %b
 * @conv: arg
 * @buff: buff[1024]
 * @i: index
 * @f: flag characters for non-custom conversion specifiers
 * Return: length of write
 */
int conv_b(va_list conv, char *buff, int i, __attribute__ ((unused)) char f)
{
	unsigned int j = va_arg(conv, unsigned int), k;
	char temp[65];

	if (j == 0)
		buff[i++] = '0';
	for (k = 0; j > 0; k++)
	{
		temp[k] = j % 2 + '0';
		j /= 2;
	}
	i = _strrev(buff, temp, i, k);
	return (i);
}

/**
 * conv_u - prints %u
 * @conv: arg
 * @buff: buff[1024]
 * @i: index
 * @f: flag characters for non-custom conversion specifiers
 * Return: length of write
 */

int conv_u(va_list conv, char *buff, int i, char f)
{
	unsigned int j = va_arg(conv, unsigned int), k;
	char temp[20];

	if (f == ' ' || f == '+')
		buff[i++] = f;
	if (j == 0)
		buff[i++] = '0';
	for (k = 0; j > 0; k++)
	{
		temp[k] = j % 10 + '0';
		j /= 10;
	}
	i = _strrev(buff, temp, i, k);
	return (i);
}
