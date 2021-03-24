/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:21:38 by jbenjy            #+#    #+#             */
/*   Updated: 2021/03/24 17:56:04 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     check_dist(char *str)
{
    if(str[0] == 'N' && str[1] == 'O')
        return (1);
    if(str[0] == 'S' && str[1] == 'O')
        return (2);
    if(str[0] == 'W' && str[1] == 'E')
        return (3);
    if(str[0] == 'E' && str[1] == 'A')
        return (4);
    return (5);
}

void    parse_path(t_global *global, char *str, int place)
{
    if(place == 1)
        global->scene.path_north = ft_strdup(str);
    if(place == 2)
        global->scene.path_south = ft_strdup(str);
    if(place == 3)
        global->scene.path_west = ft_strdup(str);
    if(place == 4)
        global->scene.path_east = ft_strdup(str);
    if(place == 5)
        global->scene.path_sprite = ft_strdup(str);
}

void    create_path(char *str,  t_global *global)
{
    char **line;

    if(!(line = ft_split(str, ' ')))
        error_handle(ERROR_ALLOCATE);
    
    if(!line[0] || !line[1])
        error_handle(ERROR_PATH);    
    
    parse_path(global, line[1], check_dist(line[0]));
    split_free(line);
}