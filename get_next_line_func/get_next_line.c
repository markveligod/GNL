# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    get_next_line.с                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckakuna <ck@ck.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/10 14:39:21 by ckakuna           #+#    #+#              #
#    Updated: 2020/05/10 14:39:21 by ckakuna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	int		count_read;
	char	buff[32];

	while ((count_read = read(fd, buff, 32)))
	{
		buff[count_read] = '\0';
		*line = ft_strjoin(*line, buff);
	}
	return (0);
}