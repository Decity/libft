/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayat <ebayat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:53:52 by ebayat            #+#    #+#             */
/*   Updated: 2023/10/05 14:33:46 by ebayat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (n > 0 && s1[i] && s2[i] && s1[i] == s2[i] && n > i)
		i++;
	return (s1[i] - s2[i]);
}

int	main(void)
{
	char *str1 = "abcz";
	char *str2 = "abcaf";

	printf("dif: %i\n", ft_strncmp(str1, str2, 4));

	printf("dif: %i\n", strncmp(str1, str2, 4));
	return (1);
}

// s1 = abc
// s2 = ab