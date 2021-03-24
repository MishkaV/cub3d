/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:01:30 by jbenjy            #+#    #+#             */
/*   Updated: 2021/03/24 20:32:23 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int     check_insert_gl(t_global *global)
{
    return(global->scene.res.x >= 0 && global->scene.res.y >= 0
    && global->scene.color_ceil >= 0 && global->scene.color_floor >= 0
    && global->scene.path_east && global->scene.path_west 
    && global->scene.path_north && global->scene.path_south
    && global->scene.path_sprite); 
}


void     line_parse(char *str, t_global *global)
{
    if (str[0] == 'R')
        create_res(str, global);
    if ((str[0] == 'C' || str[0] == 'F') && str[1] == ' ')
        create_color(str, global);
    if (str[0] == 'N' || str[0] == 'W' || str[0] == 'S' || str[0] == 'E')
        create_path(str, global);
    // if(*str)
    //     error_handle(ERROR_CONFIG);
}


void    create_scene(char *file, t_global *global)
{
    char    *line;
    int     fd;
    int     gnl;

    fd = open(file, O_RDONLY);
    line = 0;
    while((gnl = get_next_line(fd, &line)) > 0)
    {
        line_parse(line, global);
        free(line);
    }
    
    if(gnl < 0)
    {
        error_handle(ERROR_READ);
        free(line);
    }

    //pass_empty(fd, &line);
    //create_map(fd, line);
}