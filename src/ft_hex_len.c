/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:53:59 by elie              #+#    #+#             */
/*   Updated: 2024/02/11 12:33:26 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_hex_len(unsigned long long int num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}
