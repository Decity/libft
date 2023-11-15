#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*byte_dst = (char *)dest;
	const char	*byte_src = (char *)src;

	if (!dest && !src)
		return (NULL);

	while (n--)
		*byte_dst++ = *byte_src++;

	return (dest);
}
