/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@ck.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 08:49:19 by ckakuna           #+#    #+#             */
/*   Updated: 2020/05/11 08:49:19 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*array;

	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2);
		if (!(array = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		i = 0;
		j = -1;
		while (s1[++j])
			array[i++] = s1[j];
		j = -1;
		while (s2[++j])
			array[i++] = s2[j];
		array[i] = '\0';
		return (array);
	}
	return (NULL);
}

char	*ft_strnew(size_t size)
{
	char	*array;
	size_t	i;

	if (!(array = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[i] = 0;
		i++;
	}
	return (array);
}

char	*ft_strchr(const char *str, int ch)
{
	int		i;
	char	c;
	char	*s;

	i = 0;
	c = (char)ch;
	s = (char *)str;
	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return (s + i);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	char	*arr;
	int		i;

	i = 0;
	while (str[i])
		i++;
	arr = (char *)malloc(sizeof(char) * (i + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}