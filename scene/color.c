/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:53:31 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/05 21:43:32 by jbenjy           ###   ########.fr       */
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
    char **color;
    
    if(!(line = ft_split(str, ' ')))
        error_handle(ERROR_ALLOCATE, global);
    
    check_number_arg(line, 2, ERROR_COLOR, global);
    
    if (!(color = ft_split(line[1], ',')))
        error_handle(ERROR_ALLOCATE, global);
    
    check_number_arg(color, 3, ERROR_COLOR, global);
    
    if(!color[0] || !color[1] || !color[2] || 
        !check_num(color[0]) || !check_num(color[1]) || !check_num(color[2]))
        error_handle(ERROR_COLOR, global);
        
    parse_color(global, color, str[0]);
    split_free(color);
    split_free(line);
}