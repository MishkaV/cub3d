/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:48:41 by jbenjy            #+#    #+#             */
/*   Updated: 2021/03/24 17:23:14 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    split_free(char **str)
{
    int count;

    count = 0;
    while (str[count])
    {
        free(str[count]);
        count++;
    }
    free(str[count]);
    free(str);
}

int     check_num(char *str)
{
    if(!str)
        return (0);
    while(ft_isdigit(*str))
        str++;
    if(!*str)
        return (1);
    return (0);
}


void    create_res(char *str,  t_global *global)
{
    char **line;

    if(!(line = ft_split(str + 2, ' ')))
        error_handle(ERROR_ALLOCATE);
    
    if(!line[0] || !line[1] || !check_num(line[0]) || !check_num(line[1]))
        error_handle(ERROR_RES);    
    
    global->scene.res = create_vector(ft_atoi(line[0]), ft_atoi(line[1]));
    global->scene.res.x = abs(global->scene.res.x) > MAX_X ? MAX_X : global->scene.res.x;
    global->scene.res.x = abs(global->scene.res.x) < MIN_X ? MIN_X : global->scene.res.x;
    global->scene.res.y = abs(global->scene.res.y) > MAX_Y ? MAX_Y : global->scene.res.y;
    global->scene.res.y = abs(global->scene.res.y) < MIN_Y ? MIN_Y : global->scene.res.y;
    split_free(line);
}