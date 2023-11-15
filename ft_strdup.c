#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len = ft_strlen(s) + 1;

	char*	new_str = ft_calloc(len, sizeof(char));
	if (!new_str)
		return (NULL);

	ft_strlcpy(new_str, s, len);

	return (new_str);
}
