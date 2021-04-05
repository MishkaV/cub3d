/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:01:09 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/05 20:03:47 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void        init_global(t_global *global)
{
    global->scene.res.x = -1;
    global->scene.res.y = -1;
    global->scene.color_ceil = -1;
    global->scene.color_floor = -1;
    global->scene.path_east.directory = 0;
    global->scene.path_north.directory = 0;
    global->scene.path_south.directory = 0;
    global->scene.path_west.directory = 0;
    global->scene.path_sprite.directory = 0;   
}

int			main(int argc, char **argv)
{
    t_global global;
    
    init_global(&global);
    arg_checker(argc, argv);
    scene_create(argv[1], &global);
    
    printf("Res: x = %d, y = %d\n", global.scene.res.x, global.scene.res.y);
    printf("Color: floor = %d, ceil = %d\n", global.scene.color_floor, global.scene.color_ceil);
    printf("NO: %s\n", global.scene.path_north.directory);
    printf("EA: %s\n", global.scene.path_east.directory);;
    printf("SO: %s\n", global.scene.path_south.directory);;
    printf("WE: %s\n", global.scene.path_west.directory);;
    printf("S: %s\n", global.scene.path_sprite.directory);
    
	return (0);
}