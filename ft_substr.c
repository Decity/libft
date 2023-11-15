#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	if (!s)
		return (NULL);

	if (start > ft_strlen(s))
		len = 0;
	else if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;

	char*	return_str = ft_calloc((len + 1), sizeof(char));
	if (!return_str)
		return (NULL);

	size_t	i = 0;
	while (len-- && s[start])
		return_str[i++] = s[start++];

	return (return_str);
}
