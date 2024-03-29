/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:31:13 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/22 17:01:41 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_subs(char const *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static void	free_arr(char **arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(arr[i++]);
	free(arr);
}

static char	**return_fun(char **arr, int i)
{
	free_arr(arr, i);
	return (0);
}

static char	**push(char **arr, int count, char *s, char c)
{
	int		i;
	int		j;
	char	*start;

	i = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		start = s;
		while (*s != c && *s)
			s++;
		arr[i] = malloc(sizeof(char) * (s - start + 2));
		if (!arr[i])
			return (return_fun(arr, i));
		j = 0;
		while (start != s)
			arr[i][j++] = *start++;
		arr[i][j] = '\0';
		i++;
	}
	arr[i] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		count;

	if (!s)
		return (0);
	count = count_subs(s, c);
	arr = malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (0);
	arr = push(arr, count, (char *)s, c);
	return (arr);
}
