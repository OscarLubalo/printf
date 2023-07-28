#include "main.h"
/**
 * eval_format - examines format specifiers and delegates printing to
 * appropriate function
 * @format: first string argument
 * @val: va_list arguments list from variadic function
 * Return: number of caharacters printed
 */
int eval_format(const char *format, va_list val)
{
	int form_len = 0;
	int p = 0;

	while (format[p] != 0)
	{
		if (format[p] == '%')
		{
			p++;
			if (format[p] == 'c')
			{
				char ch = va_arg(val, int);
				print_char(ch, &form_len);
			}
			else if (format[p] == 's')
			{
				char *chars = va_arg(val, char*);
				print_string(chars, &form_len);
			}
			else if (format[p] == '%')
			{
				putchar(format[p]);
				form_len++;
			}
			else
				exit(-1);
		}
		else
		{
			putchar(format[p]);
			form_len++;
		}
		p++;
	}
	return (form_len);
}
