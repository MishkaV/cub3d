/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:01:09 by jbenjy            #+#    #+#             */
/*   Updated: 2021/03/24 18:07:44 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void        init_global(t_global *global)
{
    global->scene.res.x = -1;
    global->scene.res.y = -1;
    global->scene.color_ceil = -1;
    global->scene.color_floor = -1;
    global->scene.path_east = 0;
    global->scene.path_north = 0;
    global->scene.path_south = 0;
    global->scene.path_west = 0;
    global->scene.path_sprite = 0;   
}

int			main(int argc, char **argv)
{
    t_global global;
    
    init_global(&global);
    arg_checker(argc, argv);
    create_scene(argv[1], &global);   
	return (0);
}