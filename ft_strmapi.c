/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayat <ebayat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:58:34 by elie              #+#    #+#             */
/*   Updated: 2023/11/09 17:28:35 by ebayat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*cstr;

	i = 0;
	cstr = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!cstr || !s || !f)
		return (NULL);
	while (s[i])
	{
		cstr[i] = f(i, (char)s[i]);
		i++;
	}
	cstr[i] = '\0';
	return (cstr);
}
