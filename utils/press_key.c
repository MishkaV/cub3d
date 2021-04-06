/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 10:33:05 by mishavorozh       #+#    #+#             */
/*   Updated: 2021/04/06 22:14:20 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    end_game(t_global *global, int error)
{
    if(global->mlx_data.window)
        mlx_destroy_window(global->mlx_data.mlx, global->mlx_data.window);
    if(global->main_image.ptr)
        mlx_destroy_image(global->mlx_data.mlx, global->main_image.ptr);
    free_arguments(global);
    exit(error);
}

int     press_key(int key, t_global *global)
{
    
    if(key == KEY_ESC)
        end_game(global, 0);
    return (0);
}

int     press_close(t_global *global)
{
    end_game(global, 0);
    return (0);
}