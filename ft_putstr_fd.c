#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, (unsigned char *)s, ft_strlen(s));
}
