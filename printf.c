#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
/**
 * _printf - produces an output according to a format
 * @format: simple string or format specifier(s)
 * Return: 0
 */
int _printf(const char *format, ...)
{
	int form_len = 0;
	va_list val;
	int p = 0;

	if (format != NULL)
	{
		va_start(val, format);
		while (format[p] != '\0')
		{
			if (format[p] == '%')
			{
				p++;
				if (format[p] == 'c')
				{
					char ch = va_arg(val, int);

					putchar(ch);
					form_len += 1;
				}
				else if (format[p] == 's')
				{
					char *constr = va_arg(val, char *);

					while (*constr)
					{
						putchar(*constr);
						form_len++;
						constr++;
					}
				}
				else if (format[p] == '%')
				{
					putchar(format[p]);
					form_len += 1;
				}
				p++;
			}
			putchar(format[p]);
			form_len++;
			p++;
		}
		return (form_len);
		va_end(val);
	}
	return (-1);
}
