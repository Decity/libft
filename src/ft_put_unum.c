/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:24:17 by elie              #+#    #+#             */
/*   Updated: 2024/02/11 11:45:41 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_put_unum(unsigned long long int n)
{
	int	printed;

	printed = 0;
	if (n >= 10)
		printed += ft_put_unum(n / 10);
	return (printed + ft_putchar_fd(('0' + (n % 10)), 1));
}
