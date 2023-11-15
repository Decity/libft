#include "libft.h"

static int	is_set(char c, char const *set)
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
	if (!s1 || !set)
		return (NULL);

	size_t	start = 0;
	while (is_set(s1[start], set) && s1[start])
		start++;

	size_t	end = ft_strlen(s1);
	while (end > start && is_set(s1[end - 1], set))
		end--;

	size_t	len = end - start;
	char*	return_str = ft_calloc((len + 1), sizeof(char));
	if (!return_str)
		return (NULL);

	ft_strlcpy(return_str, &s1[start], len + 1);

	return (return_str);
}
