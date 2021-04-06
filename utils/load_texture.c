/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:11:05 by mishavorozh       #+#    #+#             */
/*   Updated: 2021/04/06 21:40:32 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    create_texture(t_global *global, t_mlx_data *mlx_data, t_picture *image, char *name)
{
    int height;
    int width;

    height = 64;
    width = 64;

    image->ptr = mlx_xpm_file_to_image(mlx_data->mlx, name, &height, &width);
    if (!image->ptr)
        error_handle(ERROR_TEXT_AL, global);
    image->data = mlx_get_data_addr(image->ptr, &image->bpp, &image->size_line, &image->endine);
}


void    init_texture(t_global *global)
{
    create_texture(global, &global->mlx_data, &global->scene.path_north, global->scene.path_north.directory);
    create_texture(global, &global->mlx_data, &global->scene.path_south, global->scene.path_south.directory);
    create_texture(global, &global->mlx_data, &global->scene.path_west, global->scene.path_west.directory);
    create_texture(global, &global->mlx_data, &global->scene.path_east, global->scene.path_east.directory);
}