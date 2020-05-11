/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@ck.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 14:39:15 by ckakuna           #+#    #+#             */
/*   Updated: 2020/05/10 14:39:15 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct		GNL
{
	int				fd;
	char			*temp_str;
	struct GNL		*next;	
}					GNL;

int		get_next_line(int fd, char **line);
int		get_base_line(int fd, char **line, char	**temp_str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnew(size_t size);
char	*ft_strchr(const char *str, int ch);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);

#endif