/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:01:30 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/23 15:44:42 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	scene_create_more(t_global *global)
{
	global->list_dist.list_dist = malloc(sizeof(double)
			* global->mlx_data.width);
	if (!global->list_dist.list_dist)
		error_handle(ERROR_ALLOCATE, global);
}

static void	finish(int gnl, t_global *global, char *line)
{
	if (gnl < 0)
	{
		error_handle(ERROR_READ, global);
		free(line);
	}
}

void	scene_create(char *file, t_global *global)
{
	char	*line;
	int		map_file;
	int		gnl;

	map_file = open(file, O_RDONLY);
	line = 0;
	gnl = get_next_line(map_file, &line);
	while (!check_insert_gl(global) && gnl > 0)
	{
		line_parse(line, global);
		free(line);
		gnl = get_next_line(map_file, &line);
	}
	finish(gnl, global, line);
	if (*line != '\0' && *line != '1' && *line != ' ')
		error_handle(ERROR_MAP, global);
	line = trim_file(map_file, global);
	map_create(line, map_file, global);
	scene_create_more(global);
}
