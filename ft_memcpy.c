/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayat <ebayat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:44:01 by ebayat            #+#    #+#             */
/*   Updated: 2023/11/09 17:11:33 by ebayat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*byte_dst;
	const char	*byte_src;

	byte_dst = (char *)dest;
	byte_src = (char *)src;
	if (!dest && !src)
		return (NULL);
	while (n-- > 0)
		*byte_dst++ = *byte_src++;
	return (dest);
}
