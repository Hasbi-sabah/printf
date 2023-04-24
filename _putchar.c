#include "main.h"

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
