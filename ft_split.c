/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:20:07 by ebayat            #+#    #+#             */
/*   Updated: 2023/11/12 20:04:13 by elie             ###   ########.fr       */
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

static void	free_array( size_t i, char **array)
{
	while (i--)
		free(array[i]);
	free(array);
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

static char	**split(const char *str, char c, char **array, size_t word_count)
{
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	start = 0;
	while (i < word_count)
	{
		while (str[start] && str[start] == c)
			start++;
		end = start;
		while (str[end] && str[end] != c)
			end++;
		array[i] = ft_strndup(&str[start], end - start);
		if (!array[i])
		{
			free_array(i, array);
			return (NULL);
		}
		i++;
		start = end;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(const char *str, char delimiter)
{
	char	**array;
	size_t	word_count;

	if (!str)
		return (NULL);
	word_count = count_parts(str, delimiter);
	array = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	array = split(str, delimiter, array, word_count);
	return (array);
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
