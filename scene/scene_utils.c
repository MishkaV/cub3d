/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:24:04 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/05 20:05:49 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			check_insert_gl(t_global *global)
{
	return(global->scene.res.x >= 0
	&& global->scene.res.y >= 0
	&& global->scene.color_ceil >= 0
	&& global->scene.color_floor >= 0
	&& global->scene.path_east.directory
	&& global->scene.path_west.directory
	&& global->scene.path_north.directory
	&& global->scene.path_south.directory
	&& global->scene.path_sprite.directory); 
}


void		line_parse(char *str, t_global *global)
{
	
	if (str[0] == 'W' || str[0] == 'N' || str[0] == 'E' || str[0] == 'S')
		create_path(str, global);
	else if (str[0] == 'R')
		create_res(str, global);
	else if ((str[0] == 'C' || str[0] == 'F') && str[1] == ' ')
		create_color(str, global);
	else if (check_insert_gl(global))
		return ;
	else 
		error_handle(ERROR_ARG);
}

char		*trim_file(int fd)
{
	char	*str;
	int		file;
	
	str = 0;
	file = get_next_line(fd, &str);
	if (file <= 0)
		error_handle(ERROR_READ);
	while (!str[0])
	{
		free(str);
		file = get_next_line(fd, &str);
		if (file <= 0)
			error_handle(ERROR_CONFIG);
	}
	return (str);
}

// void		map_create(char *str, int file)
// {
	
// }