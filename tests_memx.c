#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr_s;

	ptr_s = (unsigned char *)s;
	while (n-- > 0)
		*ptr_s++ = 0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	array = malloc(nmemb * size);
	if (!array)
		return (NULL);
	ft_bzero(array, nmemb);
	return (array);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*byteptr;

	byteptr = (const unsigned char *)s;
	while (n-- > 0)
	{
		if (*byteptr == c)
			return ((void *)byteptr);
		byteptr++;
	}
	return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*byte_dst;
	const char	*byte_src;

	byte_dst = (char *)dest;
	byte_src = (char *)src;
	while (n-- > 0)
		*byte_dst++ = *byte_src++;
	return (dest);
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *byte_dst;
	const unsigned char *byte_src;

	byte_src = (const unsigned char *)src;
	byte_dst = (unsigned char *)dest;
	if (byte_dst < byte_src)
	{
		while (n-- > 0)
			*byte_dst++ = *byte_src++;
	}
	else
	{
		byte_dst += n;
		byte_src += n;
		while (n-- > 0)
			*(--byte_dst) = *(--byte_src);
	}

	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*byteptr;

	byteptr = (unsigned char *)s;
	while (n-- > 0)
		*byteptr++ = c;

	return (byteptr);
}

int main(void)
{
	// ft_bzero
    char str_bzero[20] = "Hello, World!";

    printf("Before ft_bzero: \"%s\"\n", str_bzero);
    ft_bzero(str_bzero, 5);
    printf("After ft_bzero: \"%s\"\n\n", str_bzero);

	// ft_calloc
	size_t nmemb = 5;  // Number of elements
    size_t size = sizeof(int);  // Size of each element (integer)

    int *custom_array = (int *)ft_calloc(nmemb, size);
    int *standard_array = (int *)calloc(nmemb, size);

    // Check if both arrays are initialized to zero
	size_t i = 0;
	while (i < nmemb) {
    	if (custom_array[i] != standard_array[i]) {
    	    printf("Difference found\n");
    	    break;
  		}
   		i++;
	}


    free(custom_array);
    free(standard_array);


	// ft_memchr
    char str[] = "Hello, World!";
    void *result = ft_memchr(str, 'H', strlen(str));

    if (result) {
        printf("Character '%c' at index: %ld\n", 'H', (size_t)((char *)result - str));
    } else {
        printf("Character '%c' not in string.\n", 'H');
    }
	printf("\n");

	// ft_memcmp
    char *str1 = "aaaa";
    char *str2 = "aaza";
    size_t n = 6;

    int result_memcmp = memcmp(str1, str2, 4);
    int result_ft_memcmp = ft_memcmp(str1, str2, 4);

    printf("memcmp: %d\n", result_memcmp);
    printf("ft_memcmp: %d\n\n", result_ft_memcmp);

	// ft_memcpy
    char src[] = "Hello, underworld!";
    char dest_ft[50];
    char dest_memcpy[50];

    memcpy(dest_memcpy, src, strlen(src) + 1);
    ft_memcpy(dest_ft, src, strlen(src) + 1);

    printf("memcpy: %s\n", dest_memcpy);
    printf("ft_memcpy: %s\n", dest_ft);

    printf("strcmp: %d\n\n", strcmp(dest_ft, dest_memcpy));

	// ft memmove
	char str1_memmove[20] = "Hello, World!";
	char str2_memmove[20] = "xXxXXXxxxxXxxxxx";

	printf("before ft_memmove: %s\n", str2_memmove);
	ft_memmove(str2_memmove, str1_memmove, 13);
	printf("After ft_memmove: %s\n\n", str2_memmove);


	// ft_memset
	char str_memset[20] = "xxxxxxxxxxxx";


    printf("before ft_memset: %s\n", str_memset);

    ft_memset(str_memset, 'A', 10);
    printf("After ft_memset: %s\n", str_memset);

    memset(str_memset, 'B', 10);
    printf("After memset: %s\n", str_memset);

    return (0);
}

