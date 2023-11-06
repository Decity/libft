#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'z') || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'z')
		return (1);
	return (0);
}

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}

void tester(int (*f)(int)){
	char *set = "aAcCzZ1! 	.\n";
	while (*set){
		if (f(*set))
			printf("%c: True", *set);
		else
			printf("%c: False", *set);
		set++;
		printf("\n");
	}
	printf("\n");
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ' ');
	return (c);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ' ');
	return (c);
}



int	main(){
	printf("alnum:\n");
	tester(ft_isalnum);
	printf("alpha:\n");
	tester(ft_isalpha);
	printf("ascii:\n");
	tester(ft_isascii);
	printf("isdigit:\n");
	tester(ft_isdigit);
	printf("isprint:\n");
	tester(ft_isprint);

	printf("%c \n", ft_toupper('x'));

	printf("%c \n", ft_tolower('X'));

	return (0);
}
