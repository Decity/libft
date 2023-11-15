#include "libft.h"

static unsigned int	get_digits(int n)
{
	size_t	digits = 0;

	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		digits++;
	}

	while (n != 0)
	{
		n /= 10;
		digits++;
	}

	return (digits);
}

static void	convert(char *str, long int n, int digits, int negative)
{
	while (digits--)
	{
		str[digits] = '0' + (n % 10);
		n /= 10;
	}

	if (negative)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	int			negative = 0;
	long int	num = n;
	int			digits 	= get_digits(n);

	char* 		str = ft_calloc((digits + 1), sizeof(char));
	if (!str)
		return (NULL);

	if (num < 0)
	{
		negative = 1;
		num = -num;
	}

	convert(str, num, digits, negative);

	return (str);
}
