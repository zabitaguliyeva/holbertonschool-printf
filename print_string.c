#include <stdarg.h>
#include <unistd.h>
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
