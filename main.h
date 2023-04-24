#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * struct conversion - struct
 * @conv_spec: conversion specifier
 * @f: function to be executed
 */
struct conversion
{
	char conv_spec;
	int (*f)(va_list, char*, int, char);
};
typedef struct conversion conv_list;
int _printf(const char *format, ...);
int call_funcs(conv_list *conversion,
		va_list conv, const char *format, char *buff);
int format_checker(const char *format, int *i, int *j,
		va_list conv, char *buff, conv_list *conversion);
int _strlen(const char *s);
int _strcpy(char *dest, char *src, int i);
int _strrev(char *dest, char *src, int i, int j);
void _strcat(char *dest, char *src, int i);
int _conv_flag(const char *s, int j);
int conv_c(va_list conv, char *buff, int i, char f);
int conv_percent(va_list conv, char *buff, int i, char f);
int conv_s(va_list conv, char *buff, int i, char f);
int conv_i_d(va_list conv, char *buff, int i, char f);
int conv_b(va_list conv, char *buff, int i, char f);
int conv_u(va_list conv, char *buff, int i, char f);
int conv_o(va_list conv, char *buff, int i, char f);
int conv_x(va_list conv, char *buff, int i, char f);
int conv_X(va_list conv, char *buff, int i, char f);
int conv_S(va_list conv, char *buff, int i, char f);
int conv_p(va_list conv, char *buff, int i, char f);
int conv_r(va_list conv, char *buff, int i, char f);

#endif
