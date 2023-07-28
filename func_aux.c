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
 * @chars: string to be printes
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
