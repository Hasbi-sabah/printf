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
	int (*f)(va_list);
};

int _printf(const char *format, ...);
int _strlen(const char *s);
int _conv_flag(const char *s, int j);
int conv_c(va_list conv);
int conv_s(va_list conv);
int conv_i_d(va_list conv);

#endif
