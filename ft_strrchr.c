#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				len = ft_strlen(s);
	unsigned char	chr = (unsigned char)c;

	if (chr == '\0')
		return ((char *)s + len);

	for (; len >= 0; len--){
		if (s[len] == chr)
			return ((char *)&s[len]);
	}

	return (NULL);
}
