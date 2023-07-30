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
 * print_dec - prints decimal numbers
 * @dec: decimal number parameter
 * @form_len: character count
 * Return: void
 */
void print_dec(int dec, int *form_len)
{
	int i = 0;
	char decArr[25];
	int decLen;
	char decChar;

	if (dec < 0)
	{
		putchar('-');
		(*form_len)++;
	}
	while (dec != 0)
	{
		int rem = dec % 10;

		dec /= 10;
		decChar = rem + '0';
		decArr[i] = decChar;

		i++;
	}
	decLen = i - 1;

	while (decLen >= 0)
	{
		putchar(decArr[decLen]);
		(*form_len)++;
		decLen--;
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
		char *null = "(null)";

		if (chars == NULL)
		{
			print_string(null, form_len);
			return;
		}
		print_string(chars, form_len);
	}
	else if (*format == 'd' || *format == 'i')
	{
		int num = va_arg(val, int);

		print_dec(num, form_len);
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
