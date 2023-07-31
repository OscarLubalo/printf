#include "main.h"
/**
 * write_dec - writes array of numeric characters to stdout
 * @array: array of numeric characters
 * @arr_len: length of numeric characters
 * @form_len: length of output written to stdout
 * Return: void
 */

void write_dec(char arr[], int arr_len, int *form_len)
{
	while (arr_len >= 0)
	{
		putchar(arr[arr_len]);
		(*form_len)++;
		arr_len--;
	}
}
