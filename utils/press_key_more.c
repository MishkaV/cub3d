/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key_more.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:08:27 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/23 12:11:32 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	end_game(t_global *global, int error)
{
	if (global->mlx_data.window)
		mlx_destroy_window(global->mlx_data.mlx, global->mlx_data.window);
	if (global->main_image.ptr)
		mlx_destroy_image(global->mlx_data.mlx, global->main_image.ptr);
	free_arguments(global);
	exit(error);
}

static void	change_pos_mode1(double value1, double value2, t_global *global)
{
	int		coor;
	double	step;

	step = 0.2;
	coor = (int)(global->player.x_pos + step * value1)
		+ (int)global->player.y_pos * global->mlx_data.map.width;
	if (global->mlx_data.map.data[coor] != '1')
		global->player.x_pos += value1 * step;
	coor = (int)global->player.x_pos + (int)(global->player.y_pos
			+ step * value2)
		*global->mlx_data.map.width;
	if (global->mlx_data.map.data[coor] != '1')
		global->player.y_pos += value2 * step;
}

static void	change_pos_mode0(double value1, double value2, t_global *global)
{
	int		coor;
	double	step;

	step = 0.2;
	coor = (int)(global->player.x_pos - step * value1)
		+ (int)global->player.y_pos * global->mlx_data.map.width;
	if (global->mlx_data.map.data[coor] != '1')
		global->player.x_pos -= value1 * step;
	coor = (int)global->player.x_pos + (int)(global->player.y_pos
			- step * value2)
		*global->mlx_data.map.width;
	if (global->mlx_data.map.data[coor] != '1')
		global->player.y_pos -= value2 * step;
}

void	change_position(double value1, double value2,
	int mode, t_global *global)
{
	if (mode)
		change_pos_mode1(value1, value2, global);
	else
		change_pos_mode0(value1, value2, global);
}
