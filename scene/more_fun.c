/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 21:00:50 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/26 22:34:00 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_create_read(char *str, int file, t_list_map *list, t_global *global)
{
	int			map_file;

	map_file = get_next_line(file, &str);
	while (map_file > 0)
	{
		if (*str == '\n' || *str == '\0')
			break ;
		list = push_back_map(list, str);
		free(str);
		map_file = get_next_line(file, &str);
	}
	list = push_back_map(list, str);
	free(str);
	if (map_file < 0)
		error_handle(ERROR_READ, global);
	return (map_file);
}

void	map_create_more(t_global *global, t_list_map *list)
{
	max_len(list, global);
	count_node(list, global);
	make_array_map(list, global);
	free_list_map(list);
	check_map(global);
}
