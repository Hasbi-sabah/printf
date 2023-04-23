#include "main.h"

/**
 * conv_o - prints %o
 * @conv: arg
 * @buff: buff[1024]
 * @i: index
 * @f: flag characters for non-custom conversion specifiers
 * Return: length of write
 */
int conv_o(va_list conv, char *buff, int i, char f)
{
	unsigned int j = va_arg(conv, unsigned int), k;
	char temp[12];

	if (f == ' ' || f == '+')
		buff[i++] = f;
	if (j == 0)
		buff[i++] = '0';
	for (k = 0; j > 0; k++)
	{
		temp[k] = j % 8 + '0';
		j /= 8;
	}
	i = _strrev(buff, temp, i, k);
	return (i);
}

/**
 * conv_x - prints %x
 * @conv: arg
 * @buff: buff[1024]
 * @i: index
 * @f: flag characters for non-custom conversion specifiers
 * Return: length of write
 */
int conv_x(va_list conv, char *buff, int i, char f)
{
	unsigned int j = va_arg(conv, unsigned int), k;
	char temp[12];

	if (f == '#')
	{
		buff[i++] = '0';
		buff[i++] = 'x';
	}
	if (j == 0)
		buff[i++] = '0';
	for (k = 0; j > 0; k++)
	{
		if ((j % 16) > 9)
			temp[k] = ((j % 16) - 10) + 'a';
		else
			temp[k] = j % 16 + '0';
		j /= 16;
	}
	i = _strrev(buff, temp, i, k);
	return (i);
}

/**
 * conv_X - prints %X
 * @conv: arg
 * @buff: buff[1024]
 * @i: index
 * @f: flag characters for non-custom conversion specifiers
 * Return: length of write
 */
int conv_X(va_list conv, char *buff, int i, char f)
{
	unsigned int j = va_arg(conv, unsigned int), k;
	char temp[12];

	if (f == '#')
	{
		buff[i++] = '0';
		buff[i++] = 'x';
	}
	if (j == 0)
		buff[i++] = '0';
	for (k = 0; j > 0; k++)
	{
		if ((j % 16) > 9)
			temp[k] = ((j % 16) - 10) + 'A';
		else
			temp[k] = j % 16 + '0';
		j /= 16;
	}
	i = _strrev(buff, temp, i, k);
	return (i);
}

/**
 * conv_S - prints %S
 * @conv: arg
 * @buff: buff[1024]
 * @i: index
 * @f: flag characters for non-custom conversion specifiers
 * Return: length of write
 */
int conv_S(va_list conv, char *buff, int i, __attribute__ ((unused)) char f)
{
	char *p = va_arg(conv, char *), temp[] = "\\x00";
	int j, k, l, m;

	if (!p)
		return (write (1, "(null)", 6));
	_strcpy(buff, p, i);
	for (j = 0, m = i; j < _strlen(p); j++)
	{
		if (p[j] < 32 || p[j] >= 127)
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
			m += j;
			_strcat(buff, temp, m);
			m += _strlen(temp) - j - 1;
		}
	}
	i = _strlen(buff);
	return (i);
}

/**
 * conv_p - prints %p
 * @conv: arg
 * @buff: buff[1024]
 * @i: index
 * @f: flag characters for non-custom conversion specifiers
 * Return: length of write
 */
int conv_p(va_list conv, char *buff, int i, __attribute__ ((unused)) char f)
{
	unsigned long int j = va_arg(conv, unsigned long int);
	int k;
	char temp[20];

	if (j == 0)
	{
		buff[i++] = '(';
		buff[i++] = 'n';
		buff[i++] = 'i';
		buff[i++] = 'l';
		buff[i++] = ')';
		return (i);
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
	i = _strrev(buff, temp, i, k);
	return (i - 2);
}
