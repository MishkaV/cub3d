/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:05:45 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/23 12:51:51 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_first_last(t_global *global, int i)
{
	int		j;
	int		coor;
	char	*curr;

	j = 0;
	curr = global->mlx_data.map.data;
	while (j < global->mlx_data.map.width)
	{
		coor = j + i * global->mlx_data.map.width;
		if (curr[coor] != '1' && curr[coor] != ' ')
			error_handle(ERROR_MAP, global);
		j++;
	}
}

int	check_all_spaces(int i, t_global *global)
{
	int		j;
	int		coor;
	char	*map;

	j = 0;
	map = global->mlx_data.map.data;
	while (j < global->mlx_data.map.width)
	{
		coor = j + i * global->mlx_data.map.width;
		if (map[coor] != ' ')
			break ;
		j++;
	}
	if (j == global->mlx_data.map.width)
		return (1);
	else
		return (0);
}

void	check_str_spaces(int i, t_global *global)
{
	int		j;
	int		coor;
	int		coor_next;
	char	*map;

	map = global->mlx_data.map.data;
	if (i != 0 && i != global->mlx_data.map.height - 1)
	{
		j = 0;
		while (j < global->mlx_data.map.width)
		{
			coor = j + (i - 1) * global->mlx_data.map.width;
			coor_next = j + (i + 1) * global->mlx_data.map.width;
			if (map[coor] != '1' || map[coor_next] != '1')
				error_handle(ERROR_MAP, global);
			j++;
		}
	}
}

void	check_map(t_global *global)
{
	int		i;
	char	*map;

	i = 0;
	map = global->mlx_data.map.data;
	while (i < global->mlx_data.map.height)
	{
		if (!i || i == global->mlx_data.map.height - 1)
			check_first_last(global, i);
		else
		{
			if (check_all_spaces(i, global))
				check_str_spaces(i, global);
			else
				check_map_in_empty(i, global, map);
		}
		check_map_sym(i, global, map);
		check_map_up_down(i, global, map);
		check_map_left_right(i, global, map);
		i++;
	}
}
