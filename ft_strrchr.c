/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayat <ebayat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:37:34 by ebayat            #+#    #+#             */
/*   Updated: 2023/11/10 16:55:19 by ebayat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				len;
	unsigned char	chr;

	chr = (unsigned char)c;
	len = ft_strlen(s);
	if (chr == '\0')
		return ((char *)s + len);
	while (len >= 0)
	{
		if (s[len] == chr)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
