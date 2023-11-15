#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	chr = (unsigned char)c;

	while (*s && *s != chr)
		s++;

	if (*s == chr)
		return ((char *)s);

	return (NULL);
}
