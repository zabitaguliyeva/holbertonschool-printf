#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Is a function that produces output according to a format.
 * @format: Is a character string.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    int i, j, len = 0;
    char ch;
    char *str;
    va_list ap;

    va_start(ap, format);
    for (i = 0; format[i] != '\0'; i++)
    {
        for (; format[i] != '%' && format[i] != '\0'; i++)
        {
            write(1, &format[i], 1);
            len++;
        }
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
            {
                ch = va_arg(ap, int);
                write(1, &ch, 1);
                len++;
            }
            if (format[i] == 's')
            {
                str = va_arg(ap, char *);
                if (str == NULL)
                {
                    write(1, "(null)", 6);
                    len += 6;
                }
                else
                {
                    for (j = 0; str[j] != '\0'; j++)
                    {
                        write(1, &str[j], 1);
                        len++;
                    }
                }
            }
        }
    }

    va_end(ap);
    return len;
}

