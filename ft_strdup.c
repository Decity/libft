/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayat <ebayat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:40:54 by ebayat            #+#    #+#             */
/*   Updated: 2023/10/17 14:57:21 by ebayat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strdup() function returns a pointer to a new string which is a 
// duplicate of the string s.  Memory for the new string is obtained 
// with malloc(3), and can be freed with free(3).

#include <stdio.h>

char	*ft_strdup(const char *s)
{
	char	*new_str;
	size_t	i;

	i = 0;
	new_str = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strcpy(new_str, s);
	return (new_str);
}