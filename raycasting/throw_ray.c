/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:32:25 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/22 20:22:53 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	paint_column_more(int i, int x, t_global *global)
{
	int	screen_y;
	int	tex_y;
	int	coor_m;
	int	coor_n;

	screen_y = i - global->mlx_data.height / 2
		+ global->raytrace.col_height / 2;
	tex_y = screen_y * 64 / global->raytrace.col_height;
	coor_m = i * global->main_image.size_line + 4 * x;
	coor_n = tex_y * global->raytrace.texture->size_line
		+ 4 * (int)(global->raytrace.height_wall * 64);
	global->main_image.data[coor_m] = global->raytrace.texture->data[coor_n];
	global->main_image.data[coor_m + 1]
		= global->raytrace.texture->data[coor_n + 1];
	global->main_image.data[coor_m + 2]
		= global->raytrace.texture->data[coor_n + 2];
	global->main_image.data[coor_m + 3]
		= global->raytrace.texture->data[coor_n + 3];
}

static void	paint_column(int x, t_global *global)
{
	int	i;
	int	end;

	i = global->mlx_data.height / 2 - global->raytrace.col_height / 2;
	if (i < 0)
		i = 0;
	end = global->mlx_data.height / 2
		+ global->raytrace.col_height / 2;
	if (end >= global->mlx_data.height)
		end = global->mlx_data.height -1;
	while (i < end)
	{
		paint_column_more(i, x, global);
		i++;
	}
}

static void	paint_sprite_more(t_global *global, int len_list)
{
	int				i;
	t_sprite		*list;
	t_var_sprite	variable;
	int				*range;

	i = 0;
	list = malloc(sizeof(t_sprite) * len_list);
	if (!list)
		error_handle(ERROR_ALLOCATE, global);
	range = malloc(sizeof(int) * len_list);
	if (!range)
		error_handle(ERROR_ALLOCATE, global);
	parse_list(global, list, range, len_list);
	buble_sort_list(list, range, len_list);
	while (i < len_list)
	{
		calculate_sprite(global, &list[i], &variable);
		more_calculation(global, &variable);
		paint(global, &variable);
		i++;
	}
}

static void	paint_sprite(t_global *global)
{
	int			len_list;

	len_list = count_node_sprite(global->list_sprite);
	if (len_list)
		paint_sprite_more(global, len_list);
}

void	try_beauty_wall(t_global *global)
{
	int	x;

	x = 0;
	while (x < global->mlx_data.width)
	{
		global->list_dist.curr = x;
		create_raytracing(x, global);
		create_step(global);
		find_ray(global);
		find_texture(global);
		find_height(global);
		paint_column(x, global);
		x++;
	}
	paint_sprite(global);
}
