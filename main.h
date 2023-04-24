#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>


#define DATA_TYPE int

int _length_mods(const char *s, int j);

#if H_FLAG
	#undef DATA_TYPE
	#define DATA_TYPE short int
#elif HH_FLAG
	#undef DATA_TYPE
	#define DATA_TYPE short int
#elif L_FLAG
	#undef DATA_TYPE
	#define DATA_TYPE long int
#endif
/**
 * struct conversion - struct
 * @conv_spec: conversion specifier
 * @f: function to be executed
 */
struct conversion
{
	char conv_spec;
	int (*f)(va_list, char*, int, char, int);
};
typedef struct conversion conv_list;
int _printf(const char *format, ...);
int call_funcs(conv_list *conversion,
		va_list conv, const char *format, char *buff);
int format_checker(const char *format, int *i, int *j,
		va_list conv, char *buff, conv_list *conversion);
int _field_width(const char *s, int j);
int _strlen(const char *s);
int _strcpy(char *dest, char *src, int i);
int _strrev(char *dest, char *src, int i, int j);
void _strcat(char *dest, char *src, int i);
int _rot13(char *buff, char *s, int a);

int _conv_flag(const char *s, int j);

int conv_c(va_list conv, char *buff, int i, char f, int w);
int conv_percent(va_list conv, char *buff, int i, char f, int w);
int conv_s(va_list conv, char *buff, int i, char f, int w);
int conv_i_d(va_list conv, char *buff, int i, char f, int w);
int conv_b(va_list conv, char *buff, int i, char f, int w);
int conv_u(va_list conv, char *buff, int i, char f, int w);
int conv_o(va_list conv, char *buff, int i, char f, int w);
int conv_x(va_list conv, char *buff, int i, char f, int w);
int conv_X(va_list conv, char *buff, int i, char f, int w);
int conv_S(va_list conv, char *buff, int i, char f, int w);
int conv_p(va_list conv, char *buff, int i, char f, int w);
int conv_r(va_list conv, char *buff, int i, char f, int w);
int conv_R(va_list conv, char *buff, int i, char f, int w);

#endif
