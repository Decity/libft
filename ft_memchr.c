/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:48:43 by ebayat            #+#    #+#             */
/*   Updated: 2023/11/10 11:16:30 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*byteptr;

	byteptr = (const unsigned char *)s;
	while (n-- > 0)
	{
		if (*byteptr == (unsigned char)c)
			return ((void *)byteptr);
		byteptr++;
	}
	return (NULL);
}
