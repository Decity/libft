#include "libft.h"

static int	ft_iswhitespace(char c)
{
	if ((c >= 9 && c <= 13) || (c == ' '))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i = 0;
	int	num = 0;
	int	sign = 1;


	while (ft_iswhitespace(str[i]))
		i++;

	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-' )
			sign *= -1;
		i++;
	}

	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}

	return (num * sign);
}
