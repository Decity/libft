#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*byteptr = (const unsigned char *)s;

	while (n--)
	{
		if (*byteptr == (unsigned char)c)
			return ((void *)byteptr);
		byteptr++;
	}

	return (NULL);
}
