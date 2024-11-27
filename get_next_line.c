/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abturan <abturan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:49:19 by abturan           #+#    #+#             */
/*   Updated: 2024/11/27 17:18:04 by abturan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readfile(int fd, char *leftstr)
{
	char	*temp;
	int		bytes;

	bytes = 1;
	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp)
	{
		free(leftstr);
		return (NULL);
	}
	while (!(ft_strchr_gnl(leftstr, '\n')) && bytes != 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(temp);
			free(leftstr);
			return (NULL);
		}
		temp[bytes] = '\0';
		leftstr = ft_strjoin_gnl(leftstr, temp);
	}
	free(temp);
	return (leftstr);
}

char	*ft_getline(char *leftstr)
{
	char	*buff;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (leftstr[i] != '\n' && leftstr[i])
		i++;
	buff = (char *)malloc(i + 2);
	if (!buff)
	{
		free(leftstr);
		return (NULL);
	}
	while (leftstr[j] != '\n' && leftstr[j])
	{
		buff[j] = leftstr[j];
		j++;
	}
	buff[j] = leftstr[j];
	buff[++j] = '\0';
	return (buff);
}

char	*new_leftstr(char *leftstr)
{
	int		i;
	char	*new_leftstr;

	i = 0;
	while (leftstr[i] != '\n' && leftstr[i])
		i++;
	new_leftstr = ft_substr_gnl(leftstr, (i + 1), ft_strlen_gnl(leftstr) - i);
	if (!new_leftstr)
	{
		free(leftstr);
		return (NULL);
	}
	if (!leftstr[i])
	{
		free(leftstr);
		free(new_leftstr);
		return (NULL);
	}
	free(leftstr);
	return (new_leftstr);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*leftstr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (leftstr == NULL)
	{
		leftstr = malloc(sizeof(char) * 1);
		if (!leftstr)
			return (NULL);
		leftstr[0] = '\0';
	}
	leftstr = ft_readfile(fd, leftstr);
	if (!leftstr || !*leftstr)
	{
		if (leftstr)
			free(leftstr);
		leftstr = NULL;
		return (NULL);
	}
	buff = ft_getline(leftstr);
	leftstr = new_leftstr(leftstr);
	return (buff);
}
