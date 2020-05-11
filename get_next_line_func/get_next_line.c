/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@ck.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 08:49:01 by ckakuna           #+#    #+#             */
/*   Updated: 2020/05/11 08:49:01 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_copy(char *dst, char *src)
{
	size_t i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*check_temp_str(char *temp_str, char **line)
{
	char	*temp_n;
	int		i;

	temp_n = NULL;
	i = 0;
	if (temp_str)
		if ((temp_n = ft_strchr(temp_str, '\n')))
		{
			*temp_n = '\0';
			*line = ft_strdup(temp_str);
			str_copy(temp_str, ++temp_n);
		}
		else
		{
			*line = ft_strdup(temp_str);
			while (temp_str[i])
			{
				temp_str[i] = 0;
				i++;
			}
		}			
	else
		*line = ft_strnew(1);
	return (temp_n);
}

int		get_base_line(int fd, char **line, char	**temp_str)
{
	int			count_read;
	char		*buff;
	char		*temp_n;
	char		*temp_line;

	temp_n = check_temp_str(*temp_str, line);
	buff = ft_strnew(BUFFER_SIZE);
	while (!temp_n && (count_read = read(fd, buff, BUFFER_SIZE)))
	{
		buff[count_read] = '\0';
		if ((temp_n = ft_strchr(buff, '\n')))
		{
			*temp_n = '\0';
			*temp_str = ft_strdup(++temp_n);
		}
		temp_line = *line;
		if (!(*line = ft_strjoin(*line, buff)) || count_read < 0)
			return (-1);
		free(temp_line);
	}
	return ((count_read || ft_strlen(*line)) ? 1 : 0);
}

GNL		*ft_lstnew(int fd)
{
	GNL *list;

	list = (GNL *)malloc(sizeof(GNL));
	list->fd = fd;
	list->next = NULL;
	list->temp_str = NULL;
	return (list);
}

int		get_next_line(int fd, char **line)
{
	static GNL	*list;
	GNL			*temp_list;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (list == NULL)
		list = ft_lstnew(fd);
	temp_list = (GNL *)list;
	while (temp_list->fd != fd)
	{
		if (temp_list->next == NULL)
			temp_list->next = ft_lstnew(fd);
		temp_list = temp_list->next;
	}
	return (get_base_line(temp_list->fd, line, &temp_list->temp_str));
}
