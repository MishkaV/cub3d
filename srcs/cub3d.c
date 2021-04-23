/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:01:09 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/22 21:42:55 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_mlx_data(t_global *global)
{
	int	x;
	int	y;

	x = global->mlx_data.width;
	y = global->mlx_data.height;
	global->mlx_data.mlx = mlx_init();
	if (!global->mlx_data.mlx)
		error_handle(ERROR_MLX_AL, global);
	global->mlx_data.window = mlx_new_window(global->mlx_data.mlx,
			x, y, "cub3D");
	if (!global->mlx_data.window)
		error_handle(ERROR_MLX_AL, global);
}

static void	init_main_image(t_global *global)
{
	global->main_image.ptr = mlx_new_image(global->mlx_data.mlx,
			global->mlx_data.width, global->mlx_data.height);
	global->main_image.data = mlx_get_data_addr(global->main_image.ptr,
			&global->main_image.bpp,
			&global->main_image.size_line,
			&global->main_image.endine);
}

static void	inits_more(t_global *global)
{
	init_player(global);
	inits_sprites(global);
	init_mlx_data(global);
	init_texture(global);
	init_main_image(global);
}

int	main(int argc, char **argv)
{
	t_global	global;

	init_global(&global);
	arg_checker(argc, argv, &global);
	scene_create(argv[1], &global);
	inits_more(&global);
	press_key(-5, &global);
	mlx_hook(global.mlx_data.window, 2, 1, press_key, &global);
	mlx_hook(global.mlx_data.window, 17, 0, press_close, &global);
	mlx_loop(global.mlx_data.mlx);
	return (0);
}
