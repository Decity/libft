/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:40:54 by ebayat            #+#    #+#             */
/*   Updated: 2023/11/14 17:53:02 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new_str;

	len = ft_strlen(s) + 1;
	new_str = ft_calloc(len, sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s, len);
	return (new_str);
}
