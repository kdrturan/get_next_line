/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abturan <abturan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:02:45 by abturan           #+#    #+#             */
/*   Updated: 2024/10/27 22:16:14 by abturan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*p_strdup;
	int		i;
	int		size;

	size = ft_strlen(s1);
	p_strdup = (char *)malloc(size + 1);
	i = 0;
	if (!p_strdup)
	{
		free(s1);
		return (NULL);
	}
	while (i < size)
	{
		p_strdup[i] = s1[i];
		i++;
	}
	p_strdup[size] = '\0';
	return (p_strdup);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*p_sstr;
	int		i;
	int		size;

	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if ((ft_strlen(s) - start) > len)
		size = len;
	else
		size = (ft_strlen(s) - start);
	p_sstr = (char *)malloc(size + 1);
	if (!p_sstr)
	{
		free(s);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		p_sstr[i] = s[start + i];
		i++;
	}
	p_sstr[i] = '\0';
	return (p_sstr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	char	*strjoin;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	strjoin = (char *)malloc(s1_len + s2_len + 1);
	if (!strjoin)
		return (free(s1), NULL);
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
	return (free(s1), strjoin);
}

char	*ft_strchr(char *s, int c)
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
