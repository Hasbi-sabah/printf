#include "main.h"

/**
 * conv_c - prints %c
 * @conv: arg
 * @f: flag characters for non-custom conversion specifiers
 * @w: field width
 * Return: length of write
 */

int conv_c(va_list conv, __attribute__ ((unused)) char f, int w)
{
	char c = va_arg(conv, int);
	int z = 0;

	for (w -= 1; w > 0; w--, z++)
		_putchar(' ');
	_putchar(c);
	return (z + 1);
}

/**
 * conv_s - prints %s
 * @conv: arg
 * @f: flag characters for non-custom conversion specifiers
 * @w: field width
 * Return: length of write
 */

int conv_s(va_list conv, __attribute__ ((unused)) char f, int w)
{
	char *p = va_arg(conv, char *), s[] = "(null)";
	int z = 0;

	if (!p)
	{
		for (z = 0; s[z]; z++)
			_putchar(s[z]);
		return (z);
	}
	for (w -= _strlen(p); w > 0; w--, z++)
		_putchar(' ');
	for (w = 0; p[w]; w++, z++)
		_putchar(p[w]);
	return (z);
}

/**
 * conv_i_d - prints %i and %d
 * @conv: arg
 * @f: flag characters for non-custom conversion specifiers
 * @w: field width
 * Return: length of write
 */

int conv_i_d(va_list conv, char f, int w)
{
	DATA_TYPE int j = va_arg(conv, DATA_TYPE int), k, flag = 0;
	char temp[25], min[] = "-2147483648";
	int z = 0;

	for (k = 0; k < 25; k++)
		temp[k] = 0;
	if (j < 0 && j == -2147483648)
	{
		for (z = 0; min[z]; z++)
			_putchar(min[z]);
		return (z);
	}
	if (j < 0)
	{
		j = 0 - j;
		flag = 1;
	}
	if (j == 0)
		flag = 2;
	for (k = 0; j > 0; k++)
	{
		temp[k] = j % 10 + '0';
		j /= 10;
	}
	if (flag == 2)
		temp[k++] = '0';
	if (flag == 1)
		temp[k++] = '-';
	if ((f == ' ' || f == '+') && flag != 1)
		temp[k++] = f;
	for (w -= k; w > 0; w--, z++)
		_putchar(' ');
	_strrev(temp, k);
	for (w = 0; temp[w]; w++, z++)
		_putchar(temp[w]);
	return (z);
}
/**
 * conv_b - prints %b
 * @conv: arg
 * @f: flag characters for non-custom conversion specifiers
 * @w: field width
 * Return: length of write
 */

int conv_b(va_list conv, __attribute__ ((unused)) char f,
		__attribute__ ((unused)) int w)
{
	unsigned int j = va_arg(conv, unsigned int), k;
	char temp[65];
	int z = 0;

	for (k = 0; k < 65; k++)
		temp[k] = 0;
	if (j == 0)
	{
		_putchar('0');
		return (1);
	}
	for (k = 0; j > 0; k++)
	{
		temp[k] = j % 2 + '0';
		j /= 2;
	}
	_strrev(temp, k);
	for (w = 0; temp[w]; w++, z++)
		_putchar(temp[w]);
	return (z);
}

/**
 * conv_u - prints %u
 * @conv: arg
 * @f: flag characters for non-custom conversion specifiers
 * @w: field width
 * Return: length of write
 */

int conv_u(va_list conv, char f, int w)
{
	unsigned DATA_TYPE int j = va_arg(conv, unsigned DATA_TYPE int), k, flag = 0;
	char temp[20], min[] = "4294967286";
	int z = 0;

	for (k = 0; k < 20; k++)
		temp[k] = 0;
	if (j == 4294967286)
	{
		for (z = 0; min[z]; z++)
			_putchar(min[z]);
		return (z);
	}
	if (j == 0)
		flag = 1;
	for (k = 0; j > 0; k++)
	{
		temp[k] = j % 10 + '0';
		j /= 10;
	}
	if (flag)
		temp[k++] = '0';
	if (f == ' ' || f == '+')
		temp[k++] = f;
	for (w -= k; w > 0; w--, z++)
		_putchar(' ');
	_strrev(temp, k);
	for (w = 0; temp[w]; w++, z++)
		_putchar(temp[w]);
	return (z);
}
