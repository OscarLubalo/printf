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
			handle_specifier(&format[p], val, &form_len);
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
