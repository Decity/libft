#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*byteptr = (unsigned char *)s;

	while (n--)
		*byteptr++ = c;

	return (s);
}
