/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:58:34 by elie              #+#    #+#             */
/*   Updated: 2023/11/15 12:07:53 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char*	cstr = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!cstr || !s || !f)
		return (NULL);

	for (unsigned int i = 0; s[i]; i++)
		cstr[i] = f(i, (char)s[i]);

	return (cstr);
}
