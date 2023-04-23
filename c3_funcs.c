#include "main.h"

/**
 * conv_percent - prints %%
 * @conv: arg
 * @buff: buff[1024]
 * @i: index
 * @f: flag characters for non-custom conversion specifiers
 * Return: length of write
 */

int conv_percent(__atribute__ ((unused)) va_list conv, 
		__atribute__ ((unused)) char *buff, 
		__atribute__ ((unused))int i, 
		__attribute__ ((unused)) char f)
{
	return (write(1, "%%", 1));
}
