/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayat <ebayat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:38:48 by ebayat            #+#    #+#             */
/*   Updated: 2023/11/10 15:48:17 by ebayat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhitespace(char c)
{
	if ((c >= 9 && c <= 13) || (c == ' '))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	i = 0;
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

// int main()
// {
//     const char *test_strings[] = {
//         " 123",
//         "   -456",
//         "789  ",
//         " +100",
//         " - 200",
//         "12a34",
//         "0",
//         " 2147483647",
//         " -2147483648",
//     };

//     int i = 0;
//     while (i < sizeof(test_strings) / sizeof(test_strings[0]))
//     {
//         int expected_result = atoi(test_strings[i]);
//         int custom_result = ft_atoi(test_strings[i]);

//         printf("Test String: \"%s\"\n", test_strings[i]);
//         printf("Expected Result (atoi): %d\n", expected_result);
//         printf("Custom Result (ft_atoi): %d\n\n", custom_result);

//         i++;
//     }

//     return 0;
// }
