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
 *@src: string
 *@dest: buffer
 *@i: index of starting
 *@j: string length
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


/**
 * _rot13 - printing string using code rot13
 * @buff: buffer
 * @s: string to print
 * @a: length
 *
 * Return: length
 */
int _rot13(char *s)
{
	int i, j, k;
	char og[] = "azertyuiopqsdfghjklmwxcvbnAZERTYUIOPQSDFGHJKLMWXCVBN",
	     rot[] = "nmreglhvbcdfqstuwxyzjkpioaNMREGLHVBCDFQSTUWXYZJKPIOA";

	k = _strlen(s);
	for (i = 0; i < k; i++)
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
		{
			for (j = 0; og[j] != '\0'; j++)
			{
				if (s[i] == og[j])
				{
					s[i] = rot[j];
					break;
				}
			}
		}
	}
	return (i);
}
