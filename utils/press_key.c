/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 10:33:05 by mishavorozh       #+#    #+#             */
/*   Updated: 2021/04/07 11:13:21 by jbenjy           ###   ########.fr       */
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

void    player_go(int key, t_global *global)
{
    int coor;
    
    if (key == KEY_W)
    {
        coor = (int)(global->player.x_pos + 0.5 * global->player.x_direct) + global->mlx_data.map.width * (int)global->player.y_pos;
        if (global->mlx_data.map.data[coor] == '1')
            global->player.x_pos += 0.5 * (global->player.x_direct);

        coor = (int)global->player.x_direct + (int)(global->player.y_pos + 0.5 * global->player.y_direct);
        if(global->mlx_data.map.data[coor] == '1')
            global->player.y_pos += 0.5 * (global->player.y_direct);
    }
}

// void    player_change_view(int key, t_global *global)
// {
    
// }

int     press_key(int key, t_global *global)
{
    if(key == KEY_ESC)
        end_game(global, 0);

    if(key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
        player_go(key, global);
    
    // if(key == KEY_LEFT || key == KEY_RIGHT)
    //     player_change_view(key, global);
        
    floor_paint(global);
    ceil_paint(global);
    try_beauty_wall(global);
    
    mlx_put_image_to_window(global->mlx_data.mlx, global->mlx_data.window, global->main_image.ptr, 0, 0);
    return (0);
}

int     press_close(t_global *global)
{
    end_game(global, 0);
    return (0);
}