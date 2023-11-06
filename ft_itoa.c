/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:42:35 by ebayat            #+#    #+#             */
/*   Updated: 2023/11/05 12:58:50 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	get_num_size(int n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		size++;
	}
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	size++;
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str;

	size = get_num_size(n);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (size-- > 0)
	{
		str[size] = '0' + n % 10;
		n /= 10;
	}
	return (str);
}


// function name ft_itoa
// Prototype char *ft_itoa(int n);
// Turn in files -
// Parameters n: the integer to convert.
// Return value The string representing the integer.
// NULL if the allocation fails.
// External functs. malloc
// Description Allocates (with malloc(3)) and returns a string
// representing the integer received as an argument.
// Negative numbers must be handled.
// 8
