/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:40:54 by ebayat            #+#    #+#             */
/*   Updated: 2023/11/05 13:53:26 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strdup() function returns a pointer to a new string which is a
// duplicate of the string s.  Memory for the new string is obtained
// with malloc(3), and can be freed with free(3).

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;

	new_str = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s, ft_strlen(s));
	return (new_str);
}
