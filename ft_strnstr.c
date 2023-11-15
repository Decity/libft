#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i = 0;
	size_t	little_len = ft_strlen(little);
	size_t	j;

	if (little_len == 0)
		return ((char *)big);
	while (big[i] && len > i)
	{
		j = 0;

		while (big[i + j] == little[j] && big[i + j] && len > (i + j))
		{
			if (j == little_len - 1)
				return ((char *)big + i);

			j++;
		}

		i++;
	}

	return (NULL);
}
