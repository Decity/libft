#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	ft_putchar_fd(('0' + n % 10), fd);

}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		ft_putchar_fd(*s++, fd);
}

int main() {
    int file_fd = open("output.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    if (file_fd == -1) {
        perror("Error opening the file");
        return 1;
    }

    ft_putchar_fd('A', file_fd);
    ft_putendl_fd("\nHello, World!", file_fd);
    ft_putnbr_fd(12345, file_fd);
    ft_putstr_fd("\nThis is a test.", file_fd);

    close(file_fd); // Close the file

    return 0;
}
