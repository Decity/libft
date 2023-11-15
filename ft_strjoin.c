#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (NULL);

	size_t	len = ft_strlen(s1) + ft_strlen(s2) + 1;

	char*	new_str = ft_calloc(len, sizeof(char));
	if (!new_str)
		return (NULL);

	char*	new_str_pointer = new_str;

	while (*s1)
		*new_str++ = *s1++;
	while (*s2)
		*new_str++ = *s2++;

	return (new_str_pointer);
}
