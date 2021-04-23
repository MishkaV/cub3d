/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:33:11 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/22 19:52:50 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_step(t_global *global)
{
	if (0 > global->raytrace.y_ray)
	{
		global->raytrace.y_step = -1;
		global->raytrace.y_s = global->raytrace.y_delta
			* (global->player.y_pos - global->raytrace.y_map);
	}
	else
	{
		global->raytrace.y_step = 1;
		global->raytrace.y_s = global->raytrace.y_delta
			* (-global->player.y_pos + 1.0 + global->raytrace.y_map);
	}
	if (0 > global->raytrace.x_ray)
	{
		global->raytrace.x_step = -1;
		global->raytrace.x_s = global->raytrace.x_delta
			* (global->player.x_pos - global->raytrace.x_map);
	}
	else
	{
		global->raytrace.x_step = 1;
		global->raytrace.x_s = global->raytrace.x_delta
			* (-global->player.x_pos + 1.0 + global->raytrace.x_map);
	}
}

void	create_raytracing(int x, t_global *global)
{
	global->raytrace.vector = -1 + x * 2 / (double)global->mlx_data.width;
	global->raytrace.x_ray = global->raytrace.vector
		* global->player.x_plane + global->player.x_direct;
	global->raytrace.y_ray = global->raytrace.vector
		* global->player.y_plane + global->player.y_direct;
	global->raytrace.x_delta = sqrt(1 + pow(global->raytrace.y_ray, 2)
			/ pow(global->raytrace.x_ray, 2));
	global->raytrace.y_delta = sqrt(1 + pow(global->raytrace.x_ray, 2)
			/ pow(global->raytrace.y_ray, 2));
	global->raytrace.x_map = (int)global->player.x_pos;
	global->raytrace.y_map = (int)global->player.y_pos;
}

void	find_texture(t_global *global)
{
	if (0 < global->raytrace.x_ray)
	{
		if (global->raytrace.side)
		{
			if (0 > global->raytrace.y_ray)
				global->raytrace.texture = &global->scene.path_north;
			else
				global->raytrace.texture = &global->scene.path_south;
		}
		else
			global->raytrace.texture = &global->scene.path_east;
	}
	else
	{
		if (global->raytrace.side)
		{
			if (0 > global->raytrace.y_ray)
				global->raytrace.texture = &global->scene.path_north;
			else
				global->raytrace.texture = &global->scene.path_south;
		}
		else
			global->raytrace.texture = &global->scene.path_west;
	}
}

void	find_height(t_global *global)
{
	double	dist;

	if (global->raytrace.side)
	{
		dist = ((1 - global->raytrace.y_step) / 2 + global->raytrace.y_map
				- global->player.y_pos) / global->raytrace.y_ray;
		global->list_dist.list_dist[global->list_dist.curr] = dist;
		global->raytrace.col_height = global->mlx_data.height / dist;
		global->raytrace.height_wall = global->player.x_pos
			+ dist * global->raytrace.x_ray;
		global->raytrace.height_wall -= floor(global->raytrace.height_wall);
	}
	else
	{
		dist = ((1 - global->raytrace.x_step) / 2 + global->raytrace.x_map
				- global->player.x_pos) / global->raytrace.x_ray;
		global->list_dist.list_dist[global->list_dist.curr] = dist;
		global->raytrace.col_height = global->mlx_data.height / dist;
		global->raytrace.height_wall = global->player.y_pos
			+ dist * global->raytrace.y_ray;
		global->raytrace.height_wall -= floor(global->raytrace.height_wall);
	}
}

void	find_ray(t_global *global)
{
	int	coor;

	while (1)
	{
		if (global->raytrace.y_s > global->raytrace.x_s)
		{
			global->raytrace.x_s += global->raytrace.x_delta;
			global->raytrace.x_map += global->raytrace.x_step;
			global->raytrace.side = 0;
		}
		else
		{
			global->raytrace.y_s += global->raytrace.y_delta;
			global->raytrace.y_map += global->raytrace.y_step;
			global->raytrace.side = 1;
		}
		coor = global->raytrace.x_map
			+ global->mlx_data.map.width * global->raytrace.y_map;
		if (global->mlx_data.map.data[coor] == '1')
			break ;
	}
}
