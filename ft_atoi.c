/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:38:48 by ebayat            #+#    #+#             */
/*   Updated: 2023/11/05 13:05:29 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iswhitespace(char c)
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
	while (str[i] == '+' || str[i] == '-') // should check once. return 0 if theres' multiple signs
		if (str[i] == '-')
			sign *= -1;
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

