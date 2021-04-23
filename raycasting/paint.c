/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 20:03:16 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/22 20:06:23 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	paint_more(t_global *global, t_var_sprite *var, int i, int j)
{
	int	tex_x;
	int	tex_y;

	tex_x = 64 / var->dist * (i - (var->middle - var->dist / 2));
	tex_y = 64 / var->dist * (j - (global->mlx_data.height - var->dist) / 2);
	if (global->scene.path_sprite.data[4 * tex_x
			+ global->raytrace.texture->size_line * tex_y])
	{
		global->main_image.data[4 * i + j * global->main_image.size_line]
			= global->scene.path_sprite.data[4 * tex_x
			+ global->raytrace.texture->size_line * tex_y];
		global->main_image.data[4 * i + j * global->main_image.size_line + 1]
			= global->scene.path_sprite.data[4 * tex_x
			+ global->raytrace.texture->size_line * tex_y + 1];
		global->main_image.data[4 * i + j * global->main_image.size_line + 2]
			= global->scene.path_sprite.data[4 * tex_x
			+ global->raytrace.texture->size_line * tex_y + 2];
		global->main_image.data[4 * i + j * global->main_image.size_line + 3]
			= global->scene.path_sprite.data[4 * tex_x
			+ global->raytrace.texture->size_line * tex_y + 3];
	}
}

void	paint(t_global *global, t_var_sprite *var)
{
	int	i;
	int	j;
	int	tex_x;

	i = var->x_launch;
	while (i < var->x_finish)
	{
		tex_x = 64 / var->dist * (i - (var->middle - var->dist / 2));
		if (var->y_cast < global->list_dist.list_dist[i]
			&& var->y_cast > 0 && i > 0 && i < global->mlx_data.width)
		{
			j = var->y_launch;
			while (j < var->y_finish)
			{
				paint_more(global, var, i, j);
				j++;
			}
		}
		i++;
	}
}
