#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i = 0;
	size_t	j = 0;

	while (i < size && dst[i])
		i++;

	while ((i + j + 1) < size && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}

	if (i != size)
		dst[i + j] = '\0';

	return (i + ft_strlen(src));
}
