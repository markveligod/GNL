/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@ck.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 21:09:51 by student           #+#    #+#             */
/*   Updated: 2020/05/13 07:49:48 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

typedef	struct		s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s);
char				*ft_strdup(char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char *s2, int action);
char				*ft_strchr(const char *str, int ch);
int					get_next_line(int fd, char **line);

#endif
