/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayat <ebayat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:48:43 by ebayat            #+#    #+#             */
/*   Updated: 2023/10/12 13:56:09 by ebayat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*byteptr;

	byteptr = (const unsigned char *)s;
	while (n-- > 0)
	{
		if (*byteptr == c)
			return (byteptr);
		byteptr++;
	}
	return (NULL);
}