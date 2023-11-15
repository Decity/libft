#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	if (nmemb && size && nmemb > (SIZE_MAX / size))
		return (NULL);

	void* array = malloc(nmemb * size);
	if (!array)
		return (NULL);

	ft_bzero(array, nmemb * size);

	return (array);
}
