/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:34:36 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/06 21:47:20 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void        floor_paint(t_global *global)
{
	int i;
	int j;
	char *dst;

	i = 0;
	while (i < global->mlx_data.width)
	{
		j = global->mlx_data.height/2;
		while(j < global->mlx_data.height)
		{
			dst = global->main_image.data + (j*global->main_image.size_line + i * (global->main_image.bpp / 8) );
			*(unsigned int*)dst = global->scene.color_floor;
			j++;
		}
		i++;
	}
}

void        ceil_paint(t_global *global)
{
    int i;
	int j;
	char *dst;

	i = 0;
	while (i < global->mlx_data.width)
	{
		j = 0;
		while(j < global->mlx_data.height/2)
		{
			dst = global->main_image.data + (j*global->main_image.size_line + i * (global->main_image.bpp / 8) );
			*(unsigned int*)dst = global->scene.color_ceil;
			j++;
		}
		i++;
	}
}