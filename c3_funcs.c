#include "main.h"

/**
 * conv_o - prints %o
 * @conv: arg
 * @buff: buff[1024]
 * @i: index
 * @f: flag characters for non-custom conversion specifiers
 * Return: length of write
 */
int conv_per(__attribute__ ((unused)) va_list conv,
		char *buff, int i, __attribute__ ((unused)) char f)
{
	buff[++i] = '%';
	return (i + 1);
}
