/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_map_more2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:32:58 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/23 12:35:15 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_sym(char c)
{
	return (c == '0' || c == '1' || c == '2' || c == ' '
		|| c == 'N' || c == 'E' || c == 'W' || c == 'S');
}

void	check_map_left_right(int i, t_global *global, char *map)
{
	int	j;

	j = 0;
	while (j < global->mlx_data.map.width)
	{
		if (map[j + i * global->mlx_data.map.width] == ' ')
			check_space_right(i, j, global);
		j++;
	}
	j = 0;
	while (j < global->mlx_data.map.width)
	{
		if (map[j + i * global->mlx_data.map.width] == ' ')
			check_space_left(i, j, global);
		j++;
	}
}

void	check_map_up_down(int i, t_global *global, char *map)
{
	int	j;

	j = 0;
	while (j < global->mlx_data.map.width)
	{
		if (map[j + i * global->mlx_data.map.width] == ' ')
			check_space_down(i, j, global);
		j++;
	}
	j = 0;
	while (j < global->mlx_data.map.width)
	{
		if (map[j + i * global->mlx_data.map.width] == ' ')
			check_space_up(i, j, global);
		j++;
	}
}

void	check_map_in_empty(int i, t_global *global, char *map)
{
	int	j;

	j = 0;
	while (map[j + i * global->mlx_data.map.width] == ' '
		&& j < global->mlx_data.map.width - 1)
		j++;
	if (map[j + i * global->mlx_data.map.width] != '1')
		error_handle(ERROR_MAP_CLOSE, global);
	j = global->mlx_data.map.width - 1;
	while (map[j + i * global->mlx_data.map.width] == ' ' && j >= 0)
		j--;
	if (map[j + i * global->mlx_data.map.width] != '1')
		error_handle(ERROR_MAP_CLOSE, global);
}

void	check_map_sym(int i, t_global *global, char *map)
{
	int	j;

	j = 0;
	while (j < global->mlx_data.map.width)
	{
		if (!check_sym(map[j + i * global->mlx_data.map.width]))
			error_handle(ERROR_MAP_SYM, global);
		j++;
	}
}
