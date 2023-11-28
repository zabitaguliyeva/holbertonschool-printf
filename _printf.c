#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _printf - Is a function that produces output according to a format.
 * @format: Is a character string.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, len = 0, str_len = 0;
	char ch;
	char *str;
	va_list ap;

	if (!format)
		exit(60);
	if (*format == '%' && *(format + 1) == 0)
		exit(60);

	va_start(ap, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				ch = (char)va_arg(ap, int);
				len += write(1, &ch, 1);
			}
			else if (format[i] == 's')
			{
				str_len = 0;
				str = va_arg(ap, char *);
				if (str == NULL)
					str = "(null)";
				while (str)
					str_len++;
				len += write(1, str, str_len);
			}
			else if (format[i] == '%')
			{
				ch = '%';
				len += write(1, &ch, 1);
			}
			else
			{
				ch = '%';
				len += write(1, &ch, 1);
				ch = (char)va_arg(ap, int);
				len += write(1, &ch, 1);
			}
		}
		else
		{
			i++;
			ch = (char)va_arg(ap, int);
			len += write(1, &ch, 1);
		}
	}

	va_end(ap);
	return (len);
}

