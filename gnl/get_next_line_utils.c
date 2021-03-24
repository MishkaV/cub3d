/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 10:41:55 by jbenjy            #+#    #+#             */
/*   Updated: 2021/01/13 12:06:07 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (*s == c)
		return ((char*)s);
	else
		return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	char *out;

	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	out = str;
	while (*s1)
		*out++ = *s1++;
	while (*s2)
		*out++ = *s2++;
	*out = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char *str;
	char *begin;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	begin = str;
	if (!str)
		return (NULL);
	while (*s1)
		*str++ = *s1++;
	*str = '\0';
	return (begin);
}
