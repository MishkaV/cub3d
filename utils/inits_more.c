/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 21:55:02 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/22 21:56:55 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_n_e(char c, t_global *global)
{
	if (c == 'N')
	{
		global->player.x_plane = 0.7;
		global->player.y_plane = 0;
		global->player.x_direct = 0;
		global->player.y_direct = -1;
	}
	if (c == 'E')
	{
		global->player.x_plane = 0;
		global->player.y_plane = 0.7;
		global->player.x_direct = 1;
		global->player.y_direct = 0;
	}
}

static void	init_s_w(char c, t_global *global)
{
	if (c == 'S')
	{
		global->player.x_plane = -0.7;
		global->player.y_plane = 0;
		global->player.x_direct = 0;
		global->player.y_direct = 1;
	}
	if (c == 'W')
	{
		global->player.x_plane = 0;
		global->player.y_plane = -0.7;
		global->player.x_direct = -1;
		global->player.y_direct = 0;
	}
}

void	init_vectors(char c, t_global *global, int i, int j)
{
	global->player.x_pos = j + 0.5;
	global->player.y_pos = i + 0.5;
	init_n_e(c, global);
	init_s_w(c, global);
}
