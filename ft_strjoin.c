/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:16:19 by ebayat            #+#    #+#             */
/*   Updated: 2023/11/05 14:11:18 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = (char *)malloc(len * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, ft_strlen(s1));
	ft_strlcat(new_str, s2, ft_strlen(s2));
	return (new_str);
}
