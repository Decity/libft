/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayat <ebayat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:20:07 by ebayat            #+#    #+#             */
/*   Updated: 2023/11/09 16:48:07 by ebayat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static char	*ft_strndup(const char *src, size_t n)
{
	char	*dest;
	size_t	i;

	dest = (char *)malloc(n + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static size_t	count_parts(const char *str, char delimiter)
{
	size_t	count;
	size_t	i;
	int		inside_word;

	count = 0;
	i = 0;
	inside_word = 0;
	while (str[i])
	{
		if (str[i] == delimiter)
		{
			if (inside_word)
			{
				count++;
				inside_word = 0;
			}
		}
		else
			inside_word = 1;
		i++;
	}
	if (inside_word)
		count++;
	return (count);
}

char	**ft_split(const char *str, char delimiter)
{
	char	**result;
	size_t	part_count;
	size_t	start;
	size_t	end;
	size_t	i;

	part_count = count_parts(str, delimiter);
	result = (char **)malloc((part_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	start = 0;
	while (i < part_count)
	{
		while (str[start] && str[start] == delimiter)
			start++;
		end = start;
		while (str[end] && str[end] != delimiter)
			end++;
		result[i] = ft_strndup(&str[start], end - start);
		if (!result[i])
			return (NULL);
		i++;
		start = end;
	}
	result[i] = NULL;
	return (result);
}

// int main()
// {
// 	const char *input = " 1   3  3 ";
// 	char delimiter = ' ';
// 	char **parts = ft_split(input, delimiter);

// 	if (parts)
// 	{
// 		int i = 0;
// 		while (parts[i])
// 		{
// 			printf("Part %d: %s\n", (i + 1), parts[i]);
// 			free(parts[i]);
// 			i++;
// 		}
// 		free(parts);
// 	}
// 	return 0;
// }
