/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:00:28 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/22 21:55:24 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_global(t_global *global)
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
	global->check_bmp = 0;
}

static int	check_player_sym(char c)
{
	return (c == 'N' || c == 'W' || c == 'E' || c == 'S');
}

void	init_player(t_global *global)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	global->player.x_pos = -1;
	global->player.y_pos = -1;
	while (i < global->mlx_data.map.height)
	{
		j = 0;
		while (j < global->mlx_data.map.width)
		{
			c = global->mlx_data.map.data[j + i * global->mlx_data.map.width];
			if (check_player_sym(c))
			{
				if (global->player.x_pos == -1 && global->player.y_pos == -1)
					init_vectors(c, global, i, j);
				else
					error_handle(ERROR_MAP, global);
			}
			j++;
		}
		i++;
	}
}

void	inits_sprites(t_global *global)
{
	int			i;
	int			j;
	char		c;
	t_sprite	sprite;

	i = 0;
	j = 0;
	global->list_sprite = 0;
	while (i < global->mlx_data.map.height)
	{
		j = 0;
		while (j < global->mlx_data.map.width)
		{
			c = global->mlx_data.map.data[j + i * global->mlx_data.map.width];
			if (c == '2')
			{
				sprite.x = j;
				sprite.y = i;
				global->list_sprite = push_back_sprite(global->list_sprite,
						&sprite);
			}
			j++;
		}
		i++;
	}
}
