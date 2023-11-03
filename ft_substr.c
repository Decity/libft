/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayat <ebayat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:47:49 by ebayat            #+#    #+#             */
/*   Updated: 2023/10/18 13:59:43 by ebayat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

