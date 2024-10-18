#include "get_next_line.h"
#include <fcntl.h>
#include<stdio.h>


void	ft_putstr(char *s, int fd,int size)
{
	int	i;

	i = 0;
	while (s[i] && i < size)
	{
		write(fd, &s[i], 1);
		i++;
	}
}

char *p()
{
	char *a ="kadir";
	a = a+1;
	return (a) ;
}

int main()
{
	int a = open("test.txt",O_RDONLY);
	char *s = get_next_line(a);
	ft_putstr(s,1,10);
}