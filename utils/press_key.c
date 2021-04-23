/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 10:33:05 by mishavorozh       #+#    #+#             */
/*   Updated: 2021/04/23 12:10:45 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_go(int key, t_global *global)
{
	if (key == KEY_W)
		change_position(global->player.x_direct,
			global->player.y_direct, 1, global);
	if (key == KEY_S)
		change_position(global->player.x_direct,
			global->player.y_direct, 0, global);
	if (key == KEY_A)
		change_position(global->player.x_plane,
			global->player.y_plane, 0, global);
	if (key == KEY_D)
		change_position(global->player.x_plane,
			global->player.y_plane, 1, global);
}

void	move_vector(double *x, double *y, int move)
{
	double	curr_y;
	double	curr_x;

	curr_y = *y;
	curr_x = *x;
	if (move)
	{
		*y = curr_y * cos(10 * PI / 180)
			+ curr_x * sin (10 * PI / 180);
		*x = curr_x * cos(10 * PI / 180)
			- curr_y * sin (10 * PI / 180);
	}
	else
	{
		*y = curr_y * cos(-10 * PI / 180)
			+ curr_x * sin (-10 * PI / 180);
		*x = curr_x * cos(-10 * PI / 180)
			- curr_y * sin (-10 * PI / 180);
	}
}

void	player_change_view(int key, t_global *global)
{
	if (key == KEY_LEFT)
	{
		move_vector(&global->player.x_direct, &global->player.y_direct, 0);
		move_vector(&global->player.x_plane, &global->player.y_plane, 0);
	}
	else
	{
		move_vector(&global->player.x_direct, &global->player.y_direct, 1);
		move_vector(&global->player.x_plane, &global->player.y_plane, 1);
	}
}

int	press_key(int key, t_global *global)
{
	if (key == KEY_ESC)
		end_game(global, 0);
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		player_go(key, global);
	if (key == KEY_LEFT || key == KEY_RIGHT)
		player_change_view(key, global);
	floor_paint(global);
	ceil_paint(global);
	try_beauty_wall(global);
	if (global->check_bmp)
		create_bmp(global);
	mlx_put_image_to_window(global->mlx_data.mlx,
		global->mlx_data.window, global->main_image.ptr, 0, 0);
	return (0);
}

int	press_close(t_global *global)
{
	end_game(global, 0);
	return (0);
}
