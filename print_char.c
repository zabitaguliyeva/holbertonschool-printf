#include <stdarg.h>
#include <unistd.h>
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
