#include "main.h"

/**
 * conv_o - prints %o
 * @conv: arg
 * @f: flag characters for non-custom conversion specifiers
 * @w: field width
 * Return: length of write
 */

int conv_o(va_list conv, char f, int w)
{
	unsigned DATA_TYPE int j = va_arg(conv, unsigned DATA_TYPE int), k;
	int flag = 0, z = 0;
	char temp[12];

	for (k = 0; k < 12; k++)
		temp[k] = 0;
	if (j == 0)
		flag = 1;
	for (k = 0; j > 0; k++)
	{
		temp[k] = j % 8 + '0';
		j /= 8;
	}
	if (f == '#' && !flag)
		temp[k++] = '0';
	for (w -= k; w > 0; w--, z++)
		_putchar(' ');
	if (flag)
	{
		_putchar('0');
		z++;
	}
	_strrev(temp, k);
	for (w = 0; temp[w]; w++, z++)
		_putchar(temp[w]);
	return (z);
}

/**
 * conv_x - prints %x
 * @conv: arg
 * @f: flag characters for non-custom conversion specifiers
 * @w: field width
 * Return: length of write
 */

int conv_x(va_list conv, char f, int w)
{
	unsigned DATA_TYPE int j = va_arg(conv, unsigned DATA_TYPE int), k;
	int flag = 0, z = 0;
	char temp[20];

	for (k = 0; k < 20; k++)
		temp[k] = 0;
	if (j == 0)
		flag = 1;
	for (k = 0; j > 0; k++)
	{
		if ((j % 16) > 9)
			temp[k] = ((j % 16) - 10) + 'a';
		else
			temp[k] = j % 16 + '0';
		j /= 16;
	}
	if (flag)
		temp[k++] = '0';
	if (f == '#' && !flag)
	{
		temp[k++] = 'x';
		temp[k++] = '0';
	}
	for (w -= k; w > 0; w--, z++)
		_putchar(' ');
	_strrev(temp, k);
	for (w = 0; temp[w]; w++, z++)
		_putchar(temp[w]);
	return (z);
}

/**
 * conv_X - prints %X
 * @conv: arg
 * @f: flag characters for non-custom conversion specifiers
 * @w: field width
 * Return: length of write
 */

int conv_X(va_list conv, char f, int w)
{
	unsigned DATA_TYPE int j = va_arg(conv, unsigned DATA_TYPE int), k;
	int flag = 0, z = 0;
	char temp[12];

	for (k = 0; k < 12; k++)
		temp[k] = 0;
	if (j == 0)
		flag = 1;
	for (k = 0; j > 0; k++)
	{
		if ((j % 16) > 9)
			temp[k] = ((j % 16) - 10) + 'A';
		else
			temp[k] = j % 16 + '0';
		j /= 16;
	}
	if (flag)
		temp[k++] = '0';
	if (f == '#' && !flag)
	{
		temp[k++] = 'X';
		temp[k++] = '0';
	}
	for (w -= k; w > 0; w--, z++)
		_putchar(' ');
	_strrev(temp, k);
	for (w = 0; temp[w]; w++, z++)
		_putchar(temp[w]);
	return (z);
}

/**
 * conv_S - prints %S
 * @conv: arg
 * @f: flag characters for non-custom conversion specifiers
 * @w: field width
 * Return: length of write
 */

int conv_S(va_list conv, __attribute__ ((unused)) char f,
		__attribute__ ((unused)) int w)
{
	char *p = va_arg(conv, char *), temp[] = "\\x00", null[] = "(null)";
	int j, k, l, z = 0;

	if (!p)
	{
		for (j = 0; null[j]; j++)
			_putchar(null[j]);
		return (6);
	}
	for (j = 0; p[j]; j++)
	{
		if (p[j] > 0 && (p[j] < 32 || p[j] >= 127))
		{
			l = p[j];
			for (k = 3; k != 2; k--)
			{
				if ((l % 16) > 9)
					temp[k] = ((l % 16) - 10) + 'A';
				else
					temp[k] = l % 16 + '0';
				l /= 16;
			}
			for (k = 0; k < 4; k++, z++)
				_putchar(temp[k]);
		}
		else
		{
			_putchar(p[j]);
			z++;
		}
	}
	return (z);
}

/**
 * conv_p - prints %p
 * @conv: arg
 * @f: flag characters for non-custom conversion specifiers
 * @w: field width
 * Return: length of write
 */

int conv_p(va_list conv, __attribute__ ((unused)) char f, int w)
{
	unsigned long int j = va_arg(conv, unsigned long int);
	int k, z = 0;
	char temp[20], null[] = "(nil)";

	for (k = 0; k < 20; k++)
		temp[k] = 0;
	if (j == 0)
	{
		for (j = 0; null[j]; j++)
			_putchar(null[j]);
		return (j);
	}
	for (k = 2; j > 0; k++)
	{
		if ((j % 16) > 9)
			temp[k] = ((j % 16) - 10) + 'a';
		else
			temp[k] = j % 16 + '0';
		j /= 16;
	}
	temp[k++] = 'x';
	temp[k++] = '0';
	for (w -= k; w > 0; w--, z++)
		_putchar(' ');
	_strrev(temp, k);
	for (w = 0; temp[w]; w++, z++)
		_putchar(temp[w]);
	return (z);
}
