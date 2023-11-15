#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*byte_dst = (unsigned char *)dest;
	const unsigned char	*byte_src = (const unsigned char *)src;

	if (!dest && !src)
		return (NULL);

	if (byte_dst < byte_src)
	{
		while (n--)
			*byte_dst++ = *byte_src++;
	}
	else
	{
		byte_dst += n;
		byte_src += n;
		while (n--)
			*(--byte_dst) = *(--byte_src);
	}

	return (dest);
}
