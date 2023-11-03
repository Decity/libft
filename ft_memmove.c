/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayat <ebayat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:05:45 by ebayat            #+#    #+#             */
/*   Updated: 2023/10/17 13:06:22 by ebayat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*byte_src;
	char		*byte_dest;
	size_t		i;

	byte_dest = (char *)dest;
	byte_src = (const char *)src;
	i = 0;
	if (byte_dest > byte_src)
		while (n-- > 0)
			

}


// come back to this later. I don't understand what's going on