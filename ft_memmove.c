/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayat <ebayat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:05:45 by ebayat            #+#    #+#             */
/*   Updated: 2023/11/10 16:44:16 by ebayat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*byte_dst;
	const unsigned char	*byte_src;

	if (!dest && !src)
		return (NULL);
	byte_src = (const unsigned char *)src;
	byte_dst = (unsigned char *)dest;
	if (byte_dst < byte_src)
	{
		while (n-- > 0)
			*byte_dst++ = *byte_src++;
	}
	else
	{
		byte_dst += n;
		byte_src += n;
		while (n-- > 0)
			*(--byte_dst) = *(--byte_src);
	}
	return (dest);
}
