/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:26:34 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/22 20:05:53 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_list(t_global *global, t_sprite *list, int *range, int len_list)
{
	int				i;
	t_list_sprite	*root;

	i = 0;
	root = global->list_sprite;
	while (i < len_list)
	{
		list[i].x = root->sprite.x;
		list[i].y = root->sprite.y;
		range[i] = (pow(root->sprite.x - global->player.x_pos, 2)
				+ pow(root->sprite.y - global->player.y_pos, 2));
		root = root->next;
		i++;
	}
}

void	buble_sort_list(t_sprite *list, int *range, int len_list)
{
	int			i;
	int			j;
	int			curr;
	t_sprite	curr_sprite;

	i = 0;
	while (i < len_list - 1)
	{
		j = i + 1;
		while (j < len_list)
		{
			if (range[i] < range[j])
			{
				curr = range[i];
				range[i] = range[j];
				range[j] = curr;
				curr_sprite = list[i];
				list[i] = list[j];
				list[j] = curr_sprite;
			}
			j++;
		}
		i++;
	}
}

void 	calculate_sprite(t_global *global, t_sprite *sprite, t_var_sprite *var)
{
	double			x_sprite;
	double			y_sprite;

	x_sprite = sprite->x - global->player.x_pos + 0.5;
	y_sprite = sprite->y - global->player.y_pos + 0.5;
	var->mult_const = 1.0 / (global->player.y_direct * global->player.x_plane
			- global->player.x_direct * global->player.y_plane);
	var->x_cast = (x_sprite * global->player.y_direct
			- y_sprite * global->player.x_direct) * var->mult_const;
	var->y_cast = (y_sprite * global->player.x_plane
			- x_sprite * global->player.y_plane) * var->mult_const;
	var->dist = fabs(global->mlx_data.height / var->y_cast);
	var->middle = (var->x_cast / var->y_cast + 1)
		* (global->mlx_data.width / 2);
}

void	more_calculation(t_global *global, t_var_sprite *var)
{
	var->y_launch = global->mlx_data.height / 2 - var->dist / 2;
	var->x_launch = var->middle - var->dist / 2;
	var->x_finish = var->middle + var->dist / 2;
	var->y_finish = global->mlx_data.height / 2 + var->dist / 2;
	if (0 > var->y_launch)
		var->y_launch = 0;
	if (0 > var->x_launch)
		var->x_launch = 0;
	if (global->mlx_data.height <= var->y_finish)
		var->y_finish = global->mlx_data.height - 1;
	if (global->mlx_data.width <= var->x_finish)
		var->x_finish = global->mlx_data.width - 1;
}
