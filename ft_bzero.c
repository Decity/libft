#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr_s = (unsigned char *)s;

	while (n--)
		*ptr_s++ = 0;
}
