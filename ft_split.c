#include "libft.h"

static char	*ft_strndup(const char *src, size_t n)
{
	char*	dest = ft_calloc(n + 1, sizeof(char));
	if (!dest)
		return (NULL);

	size_t	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}

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
	size_t	count = 0;
	int		inside_word = 0;

	for (size_t i = 0; str[i]; i++)
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
	}

	if (inside_word)
		count++;

	return (count);
}

static char	**split(const char *str, char c, char **array, size_t word_count)
{
	size_t	end;
	size_t	start = 0;
	size_t	i = 0;

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

		start = end;
		i++;
	}

	array[i] = NULL;

	return (array);
}

char	**ft_split(const char *str, char delimiter)
{
	if (!str)
		return (NULL);

	size_t	word_count = count_parts(str, delimiter);

	char**	array = ft_calloc((word_count + 1), sizeof(char *));
	if (!array)
		return (NULL);

	array = split(str, delimiter, array, word_count);

	return (array);
}
