#include "main.h"
/**
 * print_char - handles character printing
 * @ch: character to be printed
 * @form_len: character count
 * Return: void
 */
void print_char(char ch, int *form_len)
{
	putchar(ch);
	(*form_len)++;
}

/**
 * print_string - handles string printing
 * @chars: string to be printed
 * @form_len: character count
 * Return: void
 */
void print_string(char *chars, int *form_len)
{
	while (*chars)
	{
		putchar(*chars);
		(*form_len)++;
		chars++;
	}
}

/**
 * print_unknown - prints unknown characters
 * @format: unknown character
 * @form_len: character count
 * Return: void
 */
void print_unknown(const char *format, int *form_len)
{
	format--;
	putchar(*format);
	format++;
	putchar(*format);
	(*form_len) += 2;
}

/**
 * handle_specifier - reads format specifier and calls appropiate
 * printing function
 * @format: format specifier
 * @val: list of arguments
 * @form_len: character count
 * Return: void
 */
void handle_specifier(const char *format, va_list val, int *form_len)
{
	if (*format == 'c')
	{
		char ch = va_arg(val, int);

		print_char(ch, form_len);
	}
	else if (*format == 's')
	{
		char *chars = va_arg(val, char*);

		if (chars == (char *)0)
			exit(-1);
		print_string(chars, form_len);
	}
	else if (*format == '%')
	{
		putchar(*format);
		(*form_len)++;
	}
	else if (*format == '\0')
		exit(-1);
	else
	{
		print_unknown(format, form_len);
	}
}
