/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abturan <abturan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:10:06 by abturan           #+#    #+#             */
/*   Updated: 2024/11/27 17:18:24 by abturan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 325235
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_readfile(int fd, char *leftstr);
char	*ft_getline(char *leftstr);
char	*new_leftstr(char *leftstr);
int		ft_strlen_gnl(char *s);
char	*ft_strdup_gnl(char *s1);
char	*ft_substr_gnl(char *s, int start, int len);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr_gnl(char *s, int c);
#endif
