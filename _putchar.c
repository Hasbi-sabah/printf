#include "main.h"

/**
 * _putchar - prints a character to stdout
 * @c: character to be printed
 * Return: always 1
 */

int _putchar(char c)
{
	static char buff[1024];
	static int idx;

	if (c == -1 || idx >= 1024)
	{
		write(1, buff, idx);
		idx = 0;
	}
	if (c != -1)
		buff[idx++] = c;
	return (1);

}
