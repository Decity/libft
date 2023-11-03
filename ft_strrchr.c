/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayat <ebayat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:37:34 by ebayat            #+#    #+#             */
/*   Updated: 2023/10/12 13:42:52 by ebayat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


char	*ft_strrchr(const char *s, int c)
{
	int	j;

	j = ft_strlen(s) - 1;
	while (s[j])
	{
		if (s[j] == c)
			return (&s[j]);
		j--;
	}
	return (NULL);
}