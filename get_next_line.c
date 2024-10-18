/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abturan <abturan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:49:19 by abturan           #+#    #+#             */
/*   Updated: 2024/10/18 22:01:03 by abturan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int	s1_len;
	int	s2_len;
	int	i;
	char	*strjoin;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	strjoin = (char *)malloc(s1_len + s2_len + 1);
	if (!strjoin)
	{
		return (NULL);
	}
	while (i < s1_len)
	{
		strjoin[i] = ((char *)s1)[i];
		i++;
	}
	while (i < (s1_len + s2_len))
	{
		strjoin[i] = ((char *)s2)[i - s1_len];
		i++;
	}
	strjoin[i] = '\0';
	return (strjoin);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}


char	*ft_readstr(int	fd,char	*leftstr)
{
	char	*temp;
	int		bytes;

	bytes = 1;
	temp = (char*)malloc(BUFFERSIZE + 1);
	if(!temp)
		return (NULL);
	while(!(ft_strchr(leftstr,'\n')) && bytes != 0)
	{
		bytes = read(fd,temp,BUFFERSIZE);
		if(bytes == -1)
		{
			free(temp);
			return (NULL);
		}
		leftstr = ft_strjoin(leftstr,temp);
	}
	free(temp);
	return (leftstr);
}


char	*ft_getline(char *leftstr)
{
	char	*buff;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (leftstr[i] != '\n' && leftstr[i])
		i++;
	buff = (char*)malloc(i + 2);
	if(!buff)
		return (NULL);
	while (j < i)
	{
		buff[j] = leftstr[j];
		j++;
	}
	if(leftstr[j] == '\n')
	{
		buff[j] = leftstr[j];
		j++;
	}
	buff[j] = '\0';
	return (buff);
}

#include <stdio.h>

char	*new_leftstr(char *leftstr)
{
	int	i;
	int	j;
	char	*new_leftstr;

	i = 0;
	j = 0;
	while (leftstr[i] != '\n' && leftstr[i])
		i++;
	new_leftstr = (char*)malloc(ft_strlen(leftstr) - i + 1);
	if(!new_leftstr)
		return (NULL);
	i++;
	while (leftstr[i + j])
	{
		new_leftstr[j] = leftstr[i + j];
		j++;
	}
	free(leftstr);	
	return (new_leftstr);
}

#include <stdio.h>
char *get_next_line(int fd)
{
	char			*buff;
	static	char	*leftstr;

	if (!leftstr)
	{
		leftstr = malloc(sizeof(char) * 1);
		leftstr[0] = '\0';
	}
	leftstr = ft_readstr(fd,leftstr);
	buff = ft_getline(leftstr);
	leftstr = new_leftstr(leftstr);
	return (buff);
}
