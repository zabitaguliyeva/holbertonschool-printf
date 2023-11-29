#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * print_string - print char.
 * @list: va_list.
 *
 * Return: 1
 */
int print_string(va_list ap, int *len)
{
	int j;
	char *str;
	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";

	j = 0;
	while (str[j] != '\0')
	{
		(*len) += write(1, &str[j], 1);
		j++;
	}
	return (*len);
}
/**
 * print_char - print char.
 * @list: va_list.
 *
 * Return: 1
 */
int print_char(va_list ap)
{
	char ch = (char)va_arg(ap, int);

	return (write(1,&ch, 1));
}
/**
 * _printf - Is a function that produces output according to a format.
 * @format: Is a character string.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, len = 0;
	char ch;
	va_list ap;

	if (!format)
		exit(60);

	va_start(ap, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				return(-1);
			}
			if (format[i] == 'c')
			{
				len += print_char(ap);
			}
			else if (format [i] == 's')
			{
				print_string(ap, &len);
			}
			else if (format [i] == '%')
			{
				ch = '%';
				len += write(1, &ch, 1);
			}
			else
			{
				ch = '%';
				len += write(1, &ch, 1);
				ch = format [i];
				len += write(1, &ch, 1);
			}		
		}
		else
		{
			ch = format[i];
			len += write(1, &ch, 1);
		}
	}
	va_end(ap);
	return (len);
}
