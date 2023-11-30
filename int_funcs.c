#include "main.h"
#include "unistd.h"

unsigned int _abs(int n)
{
	
	if (n < 0)
	{
		n = n * -1;
		return (n);
	}

	return (n);
}

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

char *_itoa(int value)
{
	char buffer[1024];
	int n, i;

	n = _abs(value);

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
