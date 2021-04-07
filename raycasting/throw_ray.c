/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:32:25 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/07 11:17:52 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"




void		try_beauty_wall(t_global *global)
{
	int x;
	
	double camx;		
	double ray_x;
	double ray_y;

	double delta_x;
	double delta_y;
	
	double step_x;
	double step_y;
	
	double s_x;
	double s_y;

	

	x = 0;
	while (x < global->mlx_data.width)
	{
		camx = 2 * x / (double)global->mlx_data.width - 1;
        ray_x = global->player.x_direct + camx * global->player.x_plane; 
		ray_y = global->player.y_direct + camx * global->player.y_plane; 
		delta_x = sqrt(1 + pow(ray_y, 2)/pow(ray_x, 2));
		delta_y = sqrt(1 + pow(ray_x, 2)/pow(ray_y, 2));
		int map_x = global->player.x_pos;
		int map_y = global->player.y_pos;	


		
		if (ray_x < 0)
		{
			step_x = -1;
			s_x = 0;
		}
		else
		{
			step_x  = 1;
			s_x  = delta_x;
		}

		if (ray_y < 0)
		{
			step_y = -1;
			s_y = 0;
		}
		else
		{
			step_y  = 1;
			s_y  = delta_y;
		}
		
		int side;
		
		while (1)
		{
			if (s_x < s_y)
			{
				s_x += delta_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				s_y += delta_y;
				map_y += step_y;
				side = 1;
			}
			
			if(global->mlx_data.map.data[map_x + map_y * global->mlx_data.map.width] == '1')
				break;
		}


		t_picture *texture;
		if (ray_x > 0)
		{
			if(side)
			{
				if (ray_y < 0)
					texture = &global->scene.path_south;
				else
					texture = &global->scene.path_north;
			}
			else
				texture = &global->scene.path_east;
		}
		else
		{
			if(side)
			{
				if (ray_y < 0)
					texture = &global->scene.path_south;
				else
					texture = &global->scene.path_north;
			}
			else
				texture = &global->scene.path_west;
		}

		
		double dist = side ? (map_y - global->player.y_pos + (1 - step_y) / 2) / ray_y \
				: (map_x - global->player.x_pos + (1 - step_x) / 2) / ray_x; 
		int col_height = global->mlx_data.height/(dist);
		
		double wall = side ? global->player.x_pos + dist*ray_x :  global->player.y_pos + dist*ray_y;
		wall -= floor(wall);
		int tex_x = wall*64;


		if (col_height > global->mlx_data.height)
			col_height = global->mlx_data.height;
		
		for(int k = global->mlx_data.height/2 - col_height/2; k < global->mlx_data.height/2 + col_height/2; k++)
		{	
			int screen_y = k - global->mlx_data.height/2 + col_height/2;
			int tex_y = screen_y * 64 / col_height;

			int coor_m = k*global->main_image.size_line + 4*x;
			int coor_n = tex_y*texture->size_line + 4*tex_x;

			global->main_image.data[coor_m] = texture->data[coor_n];
			global->main_image.data[coor_m + 1] = texture->data[coor_n + 1];
			global->main_image.data[coor_m + 2] = texture->data[coor_n + 2];
			global->main_image.data[coor_m + 3] = texture->data[coor_n + 3];

		}

		x++;
	}
}
