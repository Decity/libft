#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(const char *s, unsigned int start, size_t len);


char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return;
	while (s[i])
		f(i, &s[i++]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = (char *)malloc(len * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, ft_strlen(s1));
	ft_strlcat(new_str, s2, ft_strlen(s2));
	return (new_str);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	total_len;

	total_len = ft_strlen(dst) + ft_strlen((char *)src);
	while (*dst)
		dst++;
	while (*src && size > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (total_len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	while (*src && size-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (src_len);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*cstr;

	i = 0;
	cstr = (char *)malloc((ft_strlen(s) + 1 ) * sizeof(char));
	if (!cstr || !s || !f)
		return (NULL);
	while (s[i])
	{
		cstr[i] = f(i, (char)s[i]);
		i++;
	}
	return (cstr);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (n > 0 && s1[i] && s2[i] && s1[i] == s2[i] && (int)n > i)
		i++;
	return (s1[i] - s2[i]);
}


char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_l;

	i = 0;
	little_l = ft_strlen(little);
	if (little_l == 0)
		return ((char *)big);
	while (big[i] && len > i)
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j])
		{
			if (j == little_l - 1)
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	int	j;

	j = ft_strlen(s) - 1;
	while (s[j])
	{
		if (s[j] == c)
			return ((char*)&s[j]);
		j--;
	}
	return (NULL);
}

int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	start = 0;
	end = ft_strlen(s1);
	while (is_set(s1[start], set) && s1[start])
		start++;
	while (is_set(s1[end], set) && s1[end])
		end--;
	len = end - start;
	return (ft_substr(s1, start, len));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*return_str;

	i = 0;
	return_str = (char *) malloc((len + 1) * sizeof(char));
	if (!return_str)
		return (NULL);
	while (len-- > 0 && s[start])
		return_str[i++] = s[start++];
	return_str[i] = '\0';
	return (return_str);
}



int main() {
    //   ft_strchr
    {
		printf("ft_strchr\n");
        char str[] = "Hello, World!";
        char c = 'W';
        char *original_result = strchr(str, c);
        char *custom_result = ft_strchr(str, c);
        printf("original_result: %s\n", original_result);
        printf("custom_result: %s\n", custom_result);

        c = 'Z';
        original_result = strchr(str, c);
        custom_result = ft_strchr(str, c);
        printf("original_result: %s\n", original_result);
        printf("custom_result: %s\n\n", custom_result);
    }

    //   ft_striteri
    {
		printf("ft_striteri\n");
        char str[] = "TestString";
        int len = strlen(str);
        int original_count = 0, custom_count = 0;

        void custom_callback(unsigned int i, char *c) {
            (*c) = 'X'; // Replace each character with 'X'
            custom_count++;
        }

        ft_striteri(str, custom_callback);
        printf("result: %s\n\n", str);
    }

    //   ft_strjoin
    {
		printf("ft_strjoin\n");
        const char *s1 = "Hello, ";
        const char *s2 = "World!";
        char *result = strcat(strdup(s1), s2);
        printf("result: %s\n", result);

        // Edge case with NULL input
        const char *empty_s1 = "";
        char *empty_original_result = strcat(strdup(empty_s1), s2);
        char *empty_custom_result = ft_strjoin(empty_s1, s2);
        printf("original_result: %s\n", empty_original_result);
        printf("custom_result: %s\n\n", empty_custom_result);
    }

    //   ft_strlcat
    {
		printf("ft_strlcat\n");
        char dest[14] = "Hello, ";
        const char *src = "World!";
        size_t size = sizeof(dest);

        size_t custom_result = ft_strlcat(dest, src, size);
        printf("custom_result: %zu\n", custom_result);
        printf("destination string: %s\n\n", dest);
    }

    //   ft_strlcpy
    {	printf("ft_strlcpy\n");
        char dest[14] = "Hello, ";
        const char *src = "World!";
        size_t size = sizeof(dest);

        size_t custom_result = ft_strlcpy(dest, src, size);
        printf("custom_result: %zu\n", custom_result);
        printf("destination string: %s\n\n", dest);
    }

    //   ft_strlen
    {
		printf("ft_strlen\n");
        const char *str = "Hello, World!";
        size_t original_result = strlen(str);
        size_t custom_result = ft_strlen(str);
        printf("original_result: %zu\n", original_result);
        printf("custom_result: %zu\n", custom_result);

        // Edge case with an empty string
        const char *empty_str = "";
        original_result = strlen(empty_str);
        custom_result = ft_strlen(empty_str);
        printf("original_result (Edge case): %zu\n", original_result);
        printf("custom_result (Edge case): %zu\n\n", custom_result);
    }

    //   ft_strmapi
    {
		printf("ft_strmapi\n");
        const char *str = "Hello";
        char custom_result[] = "X";
        int len = strlen(str);

        char custom_callback(unsigned int i, char c) {
            custom_result[i] = c; // Copy each character to custom_result
            return c;
        }

        char *original_result = strdup(str);
        char *custom_mapped_result = ft_strmapi(str, custom_callback);
        printf("original_result: %s\n", original_result);
        printf("custom_result: %s\n", custom_mapped_result);
        free(original_result);
        free(custom_mapped_result);

        // Edge case with an empty string
        const char *empty_str = "";
        char empty_custom_result[] = "X";

        char empty_callback(unsigned int i, char c) {
            empty_custom_result[i] = c; // Copy each character to empty_custom_result
            return c;
        }

        char *empty_mapped_result = ft_strmapi(empty_str, empty_callback);
        printf("original_result (Edge case): %s\n", empty_str);
        printf("custom_result (Edge case): %s\n\n", empty_mapped_result);
    }

    //   ft_strncmp
    {
		printf("ft_strncmp\n");
        const char *s1 = "Hello";
        const char *s2 = "Hello, World!";
        size_t n = 5;

        int original_result = strncmp(s1, s2, n);
        int custom_result = ft_strncmp(s1, s2, n);
        printf("original_result: %d\n", original_result);
        printf("custom_result: %d\n\n", custom_result);
    }

    //   ft_strnstr
    {
		printf("ft_strnstr\n");
        const char *big = "Hello, World!";
        const char *little = "World";
        size_t len = strlen(big);

        char *original_result = strstr(big, little);
        char *custom_result = ft_strnstr(big, little, len);
        printf("original_result: %p\n", original_result);
        printf("custom_result: %p\n", custom_result);

        // Edge case with empty little string
        little = "";
        original_result = strstr(big, little);
        custom_result = ft_strnstr(big, little, len);
        printf("original_result (Edge case): %p\n", original_result);
        printf("custom_result (Edge case): %p\n\n", custom_result);
    }

    //   ft_strrchr
    {
		printf("ft_strrchr\n");
        const char *str = "Hello, World!";
        int c = 'o';

        char *original_result = strrchr(str, c);
        char *custom_result = ft_strrchr(str, c);
        printf("original_result: %p\n", original_result);
        printf("custom_result: %p\n", custom_result);

        c = 'z';
        original_result = strrchr(str, c);
        custom_result = ft_strrchr(str, c);
        printf("original_result: %p\n", original_result);
        printf("custom_result: %p\n\n", custom_result);
    }

    //   ft_strtrim
    {
		printf("ft_strtrim\n");
        const char *s1 = "   Hello-  u n derworld!   ";
        const char *set = " ";
        char *custom_result = ft_strtrim(s1, set);
        printf("custom_result: %s\n\n", custom_result);
        free(custom_result);
    }

    //   ft_substr
    {
		printf("ft_substr\n");
        const char *s = "Hello, World!";
        unsigned int start = 7;
        size_t len = 6;
        char *result = ft_substr(s, start, len);
        printf("custom_result: %s\n\n", result);
        free(result);
    }

    return 0;
}
