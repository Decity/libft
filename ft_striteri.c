#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return;
	while (s[i])
		f(i, &s[i++]);
}

void print_index_and_char(unsigned int index, char *c) {
    printf("Index: %u, Character: %c\n", index, *c);
}

int main() {
    char str[] = "Hello, World!";

    printf("Original string: %s\n", str);
	ft_striteri(str, print_index_and_char);

    return (0);
}