/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:00:28 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/07 10:56:40 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void        		init_global(t_global *global)
{
	global->mlx_data.width = -1;
	global->mlx_data.height = -1;
	
	global->scene.color_ceil = -1;
	global->scene.color_floor = -1;
	global->scene.path_east.directory = 0;
	global->scene.path_north.directory = 0;
	global->scene.path_south.directory = 0;
	global->scene.path_west.directory = 0;
	global->scene.path_sprite.directory = 0;
	
	global->mlx_data.map.data = 0;
	global->mlx_data.map.height = 0;
	global->mlx_data.map.width = 0; 
}

static int			check_player_sym(char c)
{
	return (c == 'N' || c == 'W' || c == 'E' || c == 'S');
}

static void			init_vectors(char c, t_global *global)
{
	if (c == 'N')
	{
		global->player.x_plane = 0.66;
		global->player.y_plane = 0;
		global->player.x_direct = 0;
		global->player.y_direct = -1;
	}
	if (c == 'E')
	{
		global->player.x_plane = 0;
		global->player.y_plane = 0.66;
		global->player.x_direct = 1;
		global->player.y_direct = 0;
	}
	if (c == 'S')
	{
		global->player.x_plane = -0.66;
		global->player.y_plane = 0;
		global->player.x_direct = 0;
		global->player.y_direct = 1;
	}
	if (c == 'W')
	{
		global->player.x_plane = 0;
		global->player.y_plane = -0.66;
		global->player.x_direct = -1;
		global->player.y_direct = 0;
	}
}

void        		init_player(t_global *global)
{
	int     i;
	int     j;
	char    c;

	i = 0;
	j = 0;
	global->player.x_pos = -1;
	global->player.y_pos = -1;
	
	while(i < global->mlx_data.map.height)
	{
		j = 0;
		while (j < global->mlx_data.map.width)
		{
			c = global->mlx_data.map.data[j + i * global->mlx_data.map.width];
			if(check_player_sym(c))
			{
				if (global->player.x_pos == -1 && global->player.y_pos == -1)
				{
					global->player.x_pos = j + 0.5;
					global->player.y_pos = i + 0.5;
					init_vectors(c, global);
				}
				else
					error_handle(ERROR_MAP, global);
			}
			j++;
		}
		i++;
	}
}