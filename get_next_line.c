/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abturan <abturan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:49:19 by abturan           #+#    #+#             */
/*   Updated: 2024/10/24 23:03:11 by abturan          ###   ########.fr       */
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

char	*ft_strdup(const char *s1)
{
	char	*p_strdup;
	int	i;
	int	size;

	size = ft_strlen(s1);
	p_strdup = (char *)malloc(size + 1);
	i = 0;
	if (!p_strdup)
		return (NULL);
	while (i < size)
	{
		p_strdup[i] = s1[i];
		i++;
	}
	p_strdup[size] = '\0';
	return (p_strdup);
}

char	*ft_substr(char const *s,  int start, int len)
{
	char	*p_sstr;
	int	i;
	int	size;

	if (ft_strlen(s) < start)
	{
		return (ft_strdup(""));
	}
	if ((ft_strlen(s) - start) > len)
		size = len;
	else
		size = (ft_strlen(s) - start);
	p_sstr = (char *)malloc(size + 1);
	if (!p_sstr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		p_sstr[i] = s[start + i];
		i++;
	}
	p_sstr[i] = '\0';
	return (p_sstr);
}






char	*ft_strjoin(char  *s1, char const *s2)
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
	free(s1);
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
	temp = (char*)malloc(BUFFER_SIZE + 1);
	if(!temp)
		return (NULL);
	while(!(ft_strchr(leftstr,'\n')) && bytes != 0)
	{
		bytes = read(fd,temp,BUFFER_SIZE);
		if(bytes == -1)
		{
			free(temp);
			free(leftstr);
			return (NULL);
		}
		temp[bytes] = '\0';
		leftstr = ft_strjoin(leftstr,temp);
	}
	if (temp)
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
	while (leftstr[j] != '\n' && leftstr[j])
	{
		buff[j] = leftstr[j];
		j++;;
	}
	buff[j] = leftstr[j];
	buff[++j] = '\0';
	return (buff);
}

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
	if(!leftstr[i])
	{
		free(leftstr);
		free(new_leftstr);
		return (NULL);
	}
	i++;
	if (leftstr[i + j] == '\n')
	{
		new_leftstr[j] = '\n';
		j++;
	}
	while (leftstr[i + j] != '\n' && leftstr[i + j])
	{
		new_leftstr[j] = leftstr[i + j];
		j++;
	}
	new_leftstr[j] = '\0';
	free(leftstr);	
	return (new_leftstr);
}

char *get_next_line(int fd)
{
	char			*buff;
	static	char	*leftstr;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (leftstr == NULL)
	{
		leftstr = malloc(sizeof(char) * 1);
		leftstr[0] = '\0';
	}
	leftstr = ft_readstr(fd,leftstr);
	if(leftstr == NULL || leftstr[0] == '\0')
	{
		if (leftstr != NULL)
			free(leftstr);
		return (NULL);
	}
	buff = ft_getline(leftstr);
	leftstr = new_leftstr(leftstr);
	return (buff);
}
