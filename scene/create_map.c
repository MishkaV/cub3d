/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 21:48:41 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/26 22:28:06 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	make_array_map_more(t_list_map *list,
	t_global *global, char *array, int i)
{
	int	j;

	j = 0;
	while (j < (int)ft_strlen(list->data))
	{
		array[j + i * global->mlx_data.map.width] = list->data[j];
		j++;
	}
	while (j < global->mlx_data.map.width)
	{
		array[j + i * global->mlx_data.map.width] = ' ';
		j++;
	}
}

void	make_array_map(t_list_map *list, t_global *global)
{
	char	*array;
	int		i;

	array = malloc(sizeof(char *) * global->mlx_data.map.height
			* global->mlx_data.map.width);
	if (!array)
		error_handle(ERROR_ALLOCATE, global);
	i = 0;
	while (i < global->mlx_data.map.height && list)
	{
		make_array_map_more(list, global, array, i);
		list = list->next;
		i++;
	}
	global->mlx_data.map.data = array;
}

void	map_create(char *str, int file, t_global *global)
{
	int			map_file;
	t_list_map	*list;

	list = 0;
	list = push_back_map(list, str);
	map_file = map_create_read(str, file, list, global);
	if (map_file > 0)
	{
		map_file = get_next_line(file, &str);
		while (map_file > 0)
		{
			free (str);
			if (*str != '\n' && *str != '\0')
			{
				error_handle(ERROR_MAP, global);
			}
			str = 0;
			map_file = get_next_line(file, &str);
		}
	}
	map_create_more(global, list);
	// free_list_map(list);
}
