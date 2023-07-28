#include "main.h"
/**
 * _printf - produces an output according to a format
 * @format: simple string or format specifier(s)
 * Return: 0
 */
int _printf(const char *format, ...)
{
	int form_len = 0;
	va_list val;

	if (format != NULL)
	{
		va_start(val, format);
		form_len = eval_format(format, val);
		va_end(val);
		return (form_len);
	}
	return (-1);
}
