/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:53:31 by jbenjy            #+#    #+#             */
/*   Updated: 2021/03/24 17:29:42 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    parse_color(t_global *global, char **str, char place)
{
    if(place == 'C')
        global->scene.color_ceil =
            (ft_atoi(str[2]) | ft_atoi(str[1]) << 8 | ft_atoi(str[1]) << 16);
    else
        global->scene.color_floor =
            (ft_atoi(str[2]) | ft_atoi(str[1]) << 8 | ft_atoi(str[1]) << 16);    
}

void    create_color(char *str,  t_global *global)
{
    char **line;
    
    if(!(line = ft_split(str + 2, ' ')))
        error_handle(ERROR_ALLOCATE);
    
    if(!line[0] || !line[1] || !line[2] || 
        !check_num(line[0]) || !check_num(line[1]) || !check_num(line[2]))
        error_handle(ERROR_COLOR);
        
    parse_color(global, line, str[0]);
    split_free(line);
}