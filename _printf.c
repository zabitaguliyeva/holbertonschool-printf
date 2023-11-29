#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
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
				len += print_string(ap);
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
