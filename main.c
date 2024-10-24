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
	int c = open("42_with_nl",O_RDONLY);
	char *s;
	int i = 0;

	s = get_next_line(c);
	printf("%s",s);
	s = get_next_line(c);
	printf("%s",s);

}

