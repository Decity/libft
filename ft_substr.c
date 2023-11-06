/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:47:49 by ebayat            #+#    #+#             */
/*   Updated: 2023/11/05 12:56:06 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*return_str;

	i = 0;
	return_str = (char *) malloc((len + 1) * sizeof(char));
	if (!return_str)
		return (NULL);
	while (len-- > 0 && s[start])
		return_str[i++] = s[start++];
	return_str[i] = '\0';
	return (return_str);
}

