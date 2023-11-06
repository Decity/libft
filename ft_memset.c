/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:47:44 by ebayat            #+#    #+#             */
/*   Updated: 2023/11/05 14:10:10 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*byteptr;

	byteptr = (unsigned char *)s;
	while (n-- > 0)
		*byteptr++ = c;

	return (byteptr);
}
