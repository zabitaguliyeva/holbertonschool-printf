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
	int i, len = 0, j = 0;
	char ch;
	char *str;
	va_list ap;

	if (!format)
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
				len += write(1,&ch, 1);
			}
			else if (format [i] == 's')
			{
				str = va_arg(ap, char *);
				if (str == NULL)
					str = "(null)";
				
				j = 0;
				while (str[j] != '\0')
				{
					len += write(1, &str[j], 1);
					j++;
				}
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
