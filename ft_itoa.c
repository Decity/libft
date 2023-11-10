/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:42:35 by ebayat            #+#    #+#             */
/*   Updated: 2023/11/09 19:18:13 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

// size_t	ft_strlen(const char *s)
// {
// 	int	i;
// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }
// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	size_t	src_len;
// 	src_len = ft_strlen(src);
// 	while (*src && size-- > 1)
// 		*dst++ = *src++;
// 	*dst = '\0';
// 	return (src_len);
// }

static unsigned int	get_digits(int n)
{
	size_t	digits;

	digits = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		digits++;
	}
	while (n >= 10)
	{
		n /= 10;
		digits++;
	}
	digits++;
	return (digits);
}

static void	convert(char *str, int n, int digits, int is_neg)
{
	while (digits-- > 0)
	{
		str[digits] = '0' + (n % 10);
		n /= 10;
	}
	if (is_neg == 1)
		str[0] = '-';
}

char	 *ft_itoa(int n)
{
	int		digits;
	char	*str;
	int		is_neg;

	is_neg = 0;
	digits = get_digits(n);
	str = (char *)malloc((digits + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[digits] = '\0';
	if (n < 0)
	{
		if (n == INT_MIN)
		{
			ft_strlcpy(str, "-2147483648", 12);
			return (str);
		}
		is_neg = 1;
		n = -n;
	}
	convert(str, n, digits, is_neg);
	return (str);
}

// int main()
// {
//     int test_values[] = {0, 123, -456, 7890, -10000, INT_MAX, INT_MIN};
//     int i = 0;
//     while (i < sizeof(test_values) / sizeof(test_values[0]))
//     {
//         char *custom_result = ft_itoa(test_values[i]);
//         printf("Test Value: %d\n", test_values[i]);
//         printf("Result (ft_itoa): %s\n\n", custom_result);
// 		free(custom_result);
//         i++;
//     }
//     return 0;
// }
