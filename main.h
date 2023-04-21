#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct conversion - struct
 * @conv_spec: conversion specifier
 * @f: function to be executed
 */
struct conversion
{
	char conv_spec;
	int (*f)(va_list, char*, int);
};

int _printf(const char *format, ...);
int _strlen(const char *s);
int _strcpy(char *dest, char *src, int i);
int _strrev(char *dest, char *src, int i, int j);
void _strcat(char *dest, char *src, int i);
int _conv_flag(const char *s, int j);
int conv_c(va_list conv, char *buff, int i);
int conv_s(va_list conv, char *buff, int i);
int conv_i_d(va_list conv, char *buff, int i);
int conv_b(va_list conv, char *buff, int i);
int conv_u(va_list conv, char *buff, int i);
int conv_o(va_list conv, char *buff, int i);
int conv_x(va_list conv, char *buff, int i);
int conv_X(va_list conv, char *buff, int i);
int conv_S(va_list conv, char *buff, int i);
int conv_p(va_list conv, char *buff, int i);

#endif
