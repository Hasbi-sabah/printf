#include "main.h"

/**
 * _strlen - return length of s
 *@s: string
 * Return: i
 */

int _strlen(const char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;
	return (i);
}

/**
 * _strrev - copies and reverses a string
 * @i: str length
 * @s: string
 * Return: i
 */

int _strrev(char *s, int i)
{
	char temp;
	int j;

	i--;
	for (j = 0; j <= i / 2; j++)
	{
		temp = s[j];
		s[j] = s[i - j];
		s[i - j] = temp;
	}
	return (j);
}
