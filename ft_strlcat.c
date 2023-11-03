/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayat <ebayat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:33:49 by ebayat            #+#    #+#             */
/*   Updated: 2023/10/17 12:42:10 by ebayat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	total_len;

	total_len = ft_strlen(dst) + ft_strlen(src);
	while (*dst)
		*dst++;
	while (*src && size > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (total_len);
}
