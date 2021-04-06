/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 21:48:41 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/06 22:22:38 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		puts_map(t_list_map *list)
{
	while (list)
	{
		puts(list->data);
		list = list->next;
	}
}

void		make_array_map(t_list_map *list, t_global *global)
{
	char	*array;
	int		i;
	int		j;
	
	if (!(array = malloc(sizeof(char *) * global->mlx_data.map.height * global->mlx_data.map.width)))
		error_handle(ERROR_ALLOCATE, global);
	i = 0;
	while (i < global->mlx_data.map.height && list)
	{
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
		list = list->next;
		i++;
	}
	global->mlx_data.map.data = array;
}

// void		print_map(t_global *global)
// {
	
// 	for(int i = 0; i < global->mlx_data.map.height; i++)
// 	{
// 		for(int j = 0; j < global->mlx_data.map.width; j++)
// 		{
// 			printf("%c", global->mlx_data.map.data[j + i * global->mlx_data.map.width]);
// 		}
// 		printf("\n");
// 	}
// }


void		map_create(char *str, int file, t_global *global)
{
	int			map_file;
	t_list_map		*list;
	
	list = 0;
	check_first(str, global);
	list = push_back_map(list, str);
	
	while ((map_file = get_next_line(file, &str)) > 0)
	{
		check_mid(str, global, list);
		list = push_back_map(list, str);
	}
	check_last(str, global, list);
	list = push_back_map(list, str);
	
	max_len(list, global);
	count_node(list, global);
	make_array_map(list, global);
	
	//print_map(global);
	
	free_list_map(list);
}