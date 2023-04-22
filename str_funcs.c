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
 * _strcpy - copies the string pointed to by src to dest
 *@src: string
 *@dest: buffer
 *@i: index of starting
 * Return: i
 */

int _strcpy(char *dest, char *src, int i)
{
	int j;

	for (j = 0; src[j] != '\0'; j++, i++)
		dest[i] = src[j];
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

int _strrev(char *dest, char *src, int i, int j)
{
	for (; j > 0; j--, i++)
		dest[i] = src[j - 1];
	return (i);
}

/**
 * _strcat - concatenates two strings
 *@src: first string
 *@dest: second string
 *@i: index of starting
 */

void _strcat(char *dest, char *src, int i)
{
	int j, k, l;

	j = _strlen(dest);
	k = _strlen(src);
	for (l = j - 1; l > i; l--)
		dest[l + k - 1] = dest[l];
	for (l = 0; l < k; l++)
		dest[i + l] = src[l];
}
