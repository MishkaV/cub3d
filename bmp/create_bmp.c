/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:51:08 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/23 13:08:15 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	more_inits(t_global *global, unsigned char *bmp_arr)
{
	bmp_arr[10] = (unsigned char)(54);
	bmp_arr[14] = (unsigned char)(40);
	bmp_arr[18] = (unsigned char)(global->mlx_data.width % 256);
	bmp_arr[19] = (unsigned char)(global->mlx_data.width / 256 % 256);
	bmp_arr[20] = (unsigned char)(global->mlx_data.width / 256 / 256 % 256);
	bmp_arr[21] = (unsigned char)(global->mlx_data.width / 256 / 256 / 256);
	bmp_arr[22] = (unsigned char)(global->mlx_data.height % 256);
	bmp_arr[23] = (unsigned char)(global->mlx_data.height / 256 % 256);
	bmp_arr[24] = (unsigned char)(global->mlx_data.height / 256 / 256 % 256);
	bmp_arr[25] = (unsigned char)(global->mlx_data.height / 256 / 256 / 256);
	bmp_arr[26] = (unsigned char)(1);
	bmp_arr[28] = (unsigned char)(32);
}

static void	init_bmp(t_global *global, unsigned char *bmp_arr)
{
	int	i;

	i = -1;
	while (++i < 54)
		bmp_arr[i] = (unsigned char)(0);
	bmp_arr[0] = (unsigned char)(66);
	bmp_arr[1] = (unsigned char)(77);
	bmp_arr[2] = (unsigned char)((4 * global->mlx_data.height
				* global->mlx_data.width + 54) % 256);
	bmp_arr[3] = (unsigned char)((4 * global->mlx_data.height
				* global->mlx_data.width + 54) / 256 % 256);
	bmp_arr[4] = (unsigned char)((4 * global->mlx_data.height
				* global->mlx_data.width + 54) / 256 / 256 % 256);
	bmp_arr[5] = (unsigned char)((4 * global->mlx_data.height
				* global->mlx_data.width + 54) / 256 / 256 / 256);
	more_inits(global, bmp_arr);
}

static void	print_bmp(int file, t_global *global)
{
	int				i;
	int				j;
	unsigned char	c;
	int				coor;
	int				k;

	i = global->mlx_data.height - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < global->mlx_data.width)
		{
			coor = i * global->main_image.size_line + 4 * j;
			k = 0;
			while (k < 4)
			{
				c = (unsigned char)global->main_image.data[coor + k];
				write(file, &c, 1);
				k++;
			}
			j++;
		}
		i--;
	}
}

void	create_bmp(t_global *global)
{
	unsigned char	bmp_arr[54];
	int				file;

	init_bmp(global, bmp_arr);
	file = open("screenshot.bmp", O_TRUNC | O_WRONLY | O_CREAT, 0666);
	write(file, &bmp_arr, 54);
	print_bmp(file, global);
	close(file);
	end_game(global, 0);
}
