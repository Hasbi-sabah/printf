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
	int len, c = 0, i = va_arg(conv, int);
	char s[20];
	
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
	for (len = 0; i > 0; len++)
	{
		s[len] = i % 10 + '0';
		i /= 10;
	}
	c += len;
	for (len--; len >= 0; len--)
		write(1, &s[len], 1);
	return (c);
}
/**
 * conv_b - prints %b
 * @conv: arg
 * Return: length of write
*/
int conv_b(va_list conv)
{
	unsigned int i = va_arg(conv, unsigned int);
	char s[65];
	int len, c = 0;

	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	for (len = 0; i > 0; len++)
	{
		s[len] = i % 2 + '0';
		i /= 2;
	}
	c += len;
	for (len--; len >= 0; len--)
		write(1, &s[len], 1);
	return (c);
}

/**
 * conv_u - prints %u
 * @conv: arg
 * Return: length of write
 */

int conv_u(va_list conv)
{
	unsigned int i = va_arg(conv, unsigned int);
	char s[20];
	int len, c = 0;

	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	for (len = 0; i > 0; len++)
	{
		s[len] = i % 10 + '0';
		i /= 10;
	}
	c += len;
	for (len--; len >= 0; len--)
	write(1, &s[len], 1);
	return (c);
}
/**
 * conv_o - prints %u
 * @conv: arg
 * Return: length of write
 */
int conv_o(va_list conv)
{
	unsigned int i = va_arg(conv, unsigned int);
	char s[12];
	int len, c = 0;
	
	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	for (len = 0; i > 0; len++)
	{
		s[len] = i % 8 + '0';
		i /= 8;
	}
	c += len;
	for (len--; len >= 0; len--)
		write(1, &s[len], 1);
	return (c);
}
/**
 * conv_x - prints %x
 * @conv: arg
 * Return: length of write
 */
int conv_x(va_list conv)
{
	unsigned int a, i = va_arg(conv, unsigned int);
	char s[12];
	int len, c = 0;
	
	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	for (len = 0; i > 0; len++)
	{
		if ((i % 16) > 9)
		{
			a = (i % 16) - 10;
			s[len] = a + 'a';
		}
		else
			s[len] = i % 16 + '0';
		i /= 16;
	}
	c += len;
	for (len--; len >= 0; len--)
		write(1, &s[len], 1);
	return (c);
}

/**
 * conv_X - prints %X
 * @conv: arg
 * Return: length of write
 */
int conv_X(va_list conv)
{
	unsigned int a, i = va_arg(conv, unsigned int);
	char s[12];
	int len, c = 0;
	
	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	for (len = 0; i > 0; len++)
	{
		if ((i % 16) > 9)
		{
			a = (i % 16) - 10;
			s[len] = a + 'A';
		}
		else
			s[len] = i % 16 + '0';
		i /= 16;
	}
	c += len;
	for (len--; len >= 0; len--)
	write(1, &s[len], 1);
	return (c);
}
