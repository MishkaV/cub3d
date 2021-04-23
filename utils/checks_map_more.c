/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_map_more.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:15:15 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/23 12:15:59 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_space_down(int i, int j, t_global *global)
{
	char	*map;
	int		coor;

	map = global->mlx_data.map.data;
	while (i < global->mlx_data.map.height)
	{
		coor = j + i * global->mlx_data.map.width;
		if (map[coor] != ' ' && map[coor] != '1')
			error_handle(ERROR_MAP, global);
		if (map[coor] == '1')
			break ;
		i++;
	}
}

void	check_space_up(int i, int j, t_global *global)
{
	char	*map;
	int		coor;

	map = global->mlx_data.map.data;
	while (i >= 0)
	{
		coor = j + i * global->mlx_data.map.width;
		if (map[coor] != ' ' && map[coor] != '1')
			error_handle(ERROR_MAP, global);
		if (map[coor] == '1')
			break ;
		i--;
	}
}

void	check_space_right(int i, int j, t_global *global)
{
	char	*map;
	int		coor;

	map = global->mlx_data.map.data;
	while (j < global->mlx_data.map.width)
	{
		coor = j + i * global->mlx_data.map.width;
		if (map[coor] != ' ' && map[coor] != '1')
			error_handle(ERROR_MAP, global);
		if (map[coor] == '1')
			break ;
		j++;
	}
}

void	check_space_left(int i, int j, t_global *global)
{
	char	*map;
	int		coor;

	map = global->mlx_data.map.data;
	while (j >= 0)
	{
		coor = j + i * global->mlx_data.map.width;
		if (map[coor] != ' ' && map[coor] != '1')
			error_handle(ERROR_MAP, global);
		if (map[coor] == '1')
			break ;
		j--;
	}
}
