/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abturan <abturan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:49:31 by abturan           #+#    #+#             */
/*   Updated: 2024/10/24 23:02:52 by abturan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
#define BUFFER_SIZE  1
#endif




#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


#include <unistd.h>
#include <stdlib.h>
char	*get_next_line(int fd);

#endif