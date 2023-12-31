#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
/**
 * handle_percent - handles % character.
 * @len: length of printed characters.
 * Return: Void.
 */
void handle_percent(int *len)
{
	char ch;

	ch = '%';
	*len += write(1, &ch, 1);
}

/**
 * print_string - prints a char.
 * @ap: va_list.
 * @len: length of string.
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
 * @ap: va_list.
 *
 * Return: 1
 */
int print_char(va_list ap)
{
	char ch = (char)va_arg(ap, int);

	return (write(1, &ch, 1));
}

/**
 * print_int - prints an integer.
 * @value: va_list.
 * @len: length of string.
 * Return: Void.
 */
void print_int(va_list value, int *len)
{
	char *str = _itoa(va_arg(value, int));

	print_int_string(str, len);
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
				return (-1);
			if (format[i] == 'c')
				len += print_char(ap);
			else if (format[i] == 's')
				print_string(ap, &len);
			else if (format[i] == 'i' || format[i] == 'd')
				print_int(ap, &len);
			else if (format[i] == '%')
			{
				ch = '%';
				len += write(1, &ch, 1);
			}
			else
			{
				ch = '%';
				len += write(1, &ch, 1);
				ch = format[i];
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
