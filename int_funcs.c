#include "main.h"
#include <unistd.h>
#include <limits.h>

/**
 * _abs - Gets the absolute value of a number.
 * @n: Number.
 * Return: Absolute value of n.
 */
unsigned int _abs(int n)
{
	unsigned int i;
	if (n < 0)
	{
		i = n * -1;
	}
	else
		i = n;

	return (i);
}

/**
 * _reverse - Reverses a string.
 * @str: Given string.
 * @n: Length of string.
 * Return: Reversed string.
 */
char *_reverse(char *str, int n)
{
	int i, temp;

	n--;
	for (i = 0; i <= n; i++, n--)
	{
		temp = str[i];
		str[i] = str[n];
		str[n] = temp;
	}

	return (str);
}

/**
 * print_int_string - Prints a string.
 * @s: Given string.
 * @len: Count of printed characters.
 * Return: len.
 */
int print_int_string(char *s, int *len)
{
	int j = 0;

	while (s[j] != '\0')
	{
		(*len) += write(1, &s[j], 1);
		j++;
	}

	return (*len);
}

/**
 * _itoa - Writes an integer into a string.
 * @value: Int number.
 * Return: Converted value.
 */
char *_itoa(int value)
{
	char buffer[1024];
	unsigned int n;
	int i;

	if (value == INT_MIN)
	{
		n = (unsigned int)INT_MAX + 1;
	}
	else
	{
		n = _abs(value);
	}

	i = 0;
	while (n)
	{
		int r = n % 10;

		buffer[i] = 48 + r;
		i++;
		n = n / 10;
	}

	if (i == 0)
	{
		buffer[i] = '0';
		i++;
	}

	if (value < 0)
	{
		buffer[i] = '-';
		i++;
	}

	buffer[i] = '\0';

	return (_reverse(buffer, i));
}
