#include "main.h"

/**
 * conv_c - prints %c
 * @conv: arg
 * Return: length of write
 */

int conv_c(va_list conv)
{
	char c = va_arg(conv, int);

	write(1, &c, 1);
	return (1);
}

/**
 * conv_s - prints %s
 * @conv: arg
 * Return: length of write
 */

int conv_s(va_list conv)
{
	char *p = va_arg(conv, char *);

	write(1, p, _strlen(p));
	return (_strlen(p));
}

/**
 * conv_i_d - prints %i and %d
 * @conv: arg
 * Return: length of write
 */

int conv_i_d(va_list conv)
{
	int i = va_arg(conv, int);
	int b, c = 0, len;
	char *p;

	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (i < 0)
	{
		i = -i;
		c = 1;
		write(1, "-", 1);
	}
	for (len = 0, b = i; b > 0; len++)
		b /= 10;
	c += len;
	p = malloc(sizeof(int) * (len + 1));
	for (len--; i > 0; len--)
	{
		p[len] = i % 10 + '0';
		i /= 10;
	}
	write(1, p, c);
	return (c);
}
