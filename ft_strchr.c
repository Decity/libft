/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayat <ebayat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:23:13 by ebayat            #+#    #+#             */
/*   Updated: 2023/11/10 16:53:39 by ebayat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	chr;

	chr = (unsigned char)c;
	while (*s && *s != chr)
		s++;
	if (*s == chr)
		return ((char *)s);
	return (NULL);
}
