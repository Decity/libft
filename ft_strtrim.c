/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayat <ebayat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:23:31 by ebayat            #+#    #+#             */
/*   Updated: 2023/10/19 10:52:41 by ebayat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	start = 0;
	end = ft_strlen(s1);
	while (is_set(s1[start], set) && s1[start])
		start++;
	while (is_set(s1[end], set) && s1[end])
		end--;
	len = end - start;
	return (ft_substr(s1, start, len));
}