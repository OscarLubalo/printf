#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);
int eval_format(const char *format, va_list val);
void print_char(char ch, int *form_len);
void print_string(char *chars, int *form_len);

#endif /* MAIN_H */
