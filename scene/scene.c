/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:01:30 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/05 21:13:21 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void    scene_create(char *file, t_global *global)
{
    char    *line;
    int     map_file;
    int     gnl;

    map_file = open(file, O_RDONLY);
    line = 0;
    while(!check_insert_gl(global) && (gnl = get_next_line(map_file, &line)) > 0)
    {
        line_parse(line, global);
        free(line);
    }
    
    if(gnl < 0)
    {
        error_handle(ERROR_READ);
        free(line);
    }
    else
    {
        line = trim_file(map_file);
    }
    //create_map(fd, line);
}