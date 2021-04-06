/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:01:09 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/06 22:22:18 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void        init_mlx_data(t_global *global)
{
    int x;
    int y;
    
    x = global->mlx_data.width;
    y = global->mlx_data.height;
    if (!(global->mlx_data.mlx = mlx_init()))
        error_handle(ERROR_MLX_AL, global);
        
    global->mlx_data.window = mlx_new_window(global->mlx_data.mlx, x, y, "cub3D"); 
    if (!global->mlx_data.window)
        error_handle(ERROR_MLX_AL, global);
}

void        init_main_image(t_global *global)
{
    global->main_image.ptr = mlx_new_image(global->mlx_data.mlx, global->mlx_data.width, global->mlx_data.height);    
    global->main_image.data = mlx_get_data_addr(global->main_image.ptr,
    &global->main_image.bpp,
    &global->main_image.size_line,
    &global->main_image.endine);
}


int			main(int argc, char **argv)
{
    t_global global;
    
    init_global(&global);
    arg_checker(argc, argv, &global);
    scene_create(argv[1], &global);
    
    init_player(&global);
    init_mlx_data(&global);
    init_texture(&global);
    init_main_image(&global);
    
    floor_paint(&global);
    ceil_paint(&global);
    
    mlx_put_image_to_window(global.mlx_data.mlx, global.mlx_data.window, global.main_image.ptr, 0, 0);
    
    mlx_hook(global.mlx_data.window, 2, 1, press_key, &global);
    mlx_hook(global.mlx_data.window, 17, 0, press_close, &global);
    
    // printf("Res: x = %d, y = %d\n", global.mlx_data.width, global.mlx_data.height);
    // printf("Color: floor = %d, ceil = %d\n", global.scene.color_floor, global.scene.color_ceil);
    // printf("NO: %s\n", global.scene.path_north.directory);
    // printf("EA: %s\n", global.scene.path_east.directory);;
    // printf("SO: %s\n", global.scene.path_south.directory);;
    // printf("WE: %s\n", global.scene.path_west.directory);;
    // printf("S: %s\n", global.scene.path_sprite.directory);
    
    mlx_loop(global.mlx_data.mlx);
	return (0);
}