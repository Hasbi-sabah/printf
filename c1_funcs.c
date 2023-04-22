#include "main.h"

/**
 * conv_c - prints %c
 * @conv: arg
 * Return: length of write
 */

int conv_c(va_list conv, char *buff, int i, __attribute__ ((unused)) char f)
{
	char c = va_arg(conv, int);

	buff[i] = c;
	return (i + 1);
}

/**
 * conv_s - prints %s
 * @conv: arg
 * Return: length of write
 */

int conv_s(va_list conv, char *buff, int i, __attribute__ ((unused)) char f)
{
	char *p = va_arg(conv, char *);

	i = _strcpy(buff, p, i);
	return (i);
}

/**
 * conv_i_d - prints %i and %d
 * @conv: arg
 * Return: length of write
 */

int conv_i_d(va_list conv, char *buff, int i, char f)
{
	int j = va_arg(conv, int), k;
	char temp[20];
	
	if ((f == ' ' || f == '+') && j >= 0)
		buff[i++] = f;
	if (j == 0)
		buff[i++] = '0';
	if (j < 0)
	{
		j = -j;
		buff[i++] = '-';
	}
	for (k = 0; j > 0; k++)
	{
		temp[k] = j % 10 + '0';
		j /= 10;
	}
	i = _strrev(buff, temp, i, k);
	return (i);
}
/**
 * conv_b - prints %b
 * @conv: arg
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
/**
 * conv_o - prints %u
 * @conv: arg
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
 * Return: length of write
 */
int conv_S(va_list conv, char *buff, int i, __attribute__ ((unused)) char f)
{
	char *p = va_arg(conv, char *), *p_x, temp[] = "\\x00";
	int j, k, l;

	for (j = 0; j < _strlen(p); j++)
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
			p_x = malloc(_strlen(p) + _strlen(temp));
			_strcpy(p_x, p, 0);
			_strcat(p_x, temp, j);
		}
	}
	i = _strcpy(buff, p_x, i);
	free(p_x);
	return (i);
}

/**
 * conv_p - prints %p
 * @conv: arg
 * Return: length of write
 */
int conv_p(va_list conv, char *buff, int i, __attribute__ ((unused)) char f)
{
	unsigned long int j = va_arg(conv, unsigned long int);
	int k;
	char temp[20];
	
	if (j == 0)
	{
		buff[i++] = '0';
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
	i = _strrev(buff, temp, i, k++);
	return (i);
}
