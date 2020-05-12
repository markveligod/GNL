/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 21:09:38 by student           #+#    #+#             */
/*   Updated: 2020/05/12 15:19:56 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*check_fd(t_list *list, int fd)
{
	while (list)
	{
		if (list->fd == fd)
			return (list);
		list = list->next;
	}
	return (NULL);
}

t_list	*ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst)
		new->next = *lst;
	*lst = new;
	return (*lst);
}

t_list	*new_list(int fd)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (fd < 0 || !(list))
		return (NULL);
	list->fd = fd;
	list->content = ft_strdup("");
	list->next = NULL;
	return (list);
}

int		get_base_line(char **line, t_list *temp_list, t_list **static_list)
{
	int		len;
	char	*remains;
	t_list	*temp_static_list;

	temp_static_list = *static_list;
	if (!ft_strchr(temp_list->content, '\n'))
	{
		*line = ft_strdup(temp_list->content);
		if (temp_static_list != temp_list)
		{
			while (temp_static_list->next && temp_static_list->next->fd != temp_list->fd)
				temp_static_list = temp_static_list->next;
			temp_static_list->next = temp_list->next;
		}
		free(temp_list->content);
		free(temp_list);
		if (temp_static_list == temp_list)
			*static_list = NULL;
		return (0);
	}
	len = (int)(ft_strchr(temp_list->content, '\n') - temp_list->content);
	*line = ft_substr(temp_list->content, 0, len);
	remains = ft_strdup(temp_list->content + len + 1);
	free(temp_list->content);
	temp_list->content = remains;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*list;
	t_list			*temp_list;
	char			buff[BUFFER_SIZE + 1];
	char			*ch;
	int				count;

	count = 0;
	if (!line || BUFFER_SIZE <= 0 || read(fd, buff, 0) < 0)
		return (-1);
	if (!list && !(list = new_list(fd)))
		return (-1);
	temp_list = check_fd(list, fd);
	if (!(temp_list) && !(temp_list = ft_lstadd_back(&list, new_list(fd))))
		return (-1);
	ch = ft_strchr(temp_list->content, '\n');
	while (!(ch) && (count = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[count] = '\0';
		temp_list->content = ft_strjoin(temp_list->content, buff, 1);
	}
	return (get_base_line(line, temp_list, &list));
}