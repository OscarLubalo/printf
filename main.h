#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int _printf(const char *format, ...);
int eval_format(const char *format, va_list val);
void handle_specifier(const char *format, va_list val, int *form_len);
void print_char(char ch, int *form_len);
void print_string(char *chars, int *form_len);
void print_dec(int dec, int *form_len);
void print_unknown(const char *format, int *form_len);
void write_dec(char arr[], int arr_len, int *form_len);


#endif /* MAIN_H */
