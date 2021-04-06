/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:07:05 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/06 21:43:42 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		put_error(int error)
{
	if (error == ERROR_ARG)
		ft_putstr_fd("Error: Bad arguments\n", 0);
	if (error == ERROR_READ)
		ft_putstr_fd("Error: Bad reading\n", 0);
	if (error == ERROR_CONFIG)
		ft_putstr_fd("Error: Bad config\n", 0);
	if (error == ERROR_ALLOCATE)
		ft_putstr_fd("Error: Bad allocation memory\n", 0);	
	if (error == ERROR_RES)
		ft_putstr_fd("Error: Bad data in .cub file(res)\n", 0);	
	if (error == ERROR_COLOR)
		ft_putstr_fd("Error: Bad data in .cub file(color)\n", 0);	
	if (error == ERROR_PATH)
		ft_putstr_fd("Error: Bad data in .cub file(path)\n", 0);
	if (error == ERROR_MAP)
		ft_putstr_fd("Error: Bad data in .cub file(map)\n", 0);
	if (error == ERROR_MAP_MID)
		ft_putstr_fd("Error: Bad data in .cub file(map - mid part)\n", 0);
	if (error == ERROR_MAP_LAST)
		ft_putstr_fd("Error: Bad data in .cub file(map - last string)\n", 0);
	if (error == ERROR_MLX_AL)
		ft_putstr_fd("Error: Bad allocation memory(mlx)\n", 0);
	if (error == ERROR_TEXT_AL)
		ft_putstr_fd("Error: Bad allocation memory(texture)\n", 0);
}

int			cub_check(char *str)
{
	int len;

	len = ft_strlen(str);
	if (len < 5)
		return (0);
	if (!ft_strncmp(str + len - 4, ".cub", 5))
		return (1);
	return (0);
}

void		free_arguments(t_global *global)
{
	if (global->scene.path_east.directory)
		free(global->scene.path_east.directory);

	if (global->scene.path_west.directory)
		free(global->scene.path_west.directory);

	if (global->scene.path_north.directory)
		free(global->scene.path_north.directory);

	if (global->scene.path_south.directory)
		free(global->scene.path_south.directory);
		
	if (global->scene.path_sprite.directory)
		free(global->scene.path_sprite.directory);
	
	if (global->mlx_data.map.data)
		free(global->mlx_data.map.data);
}

void		error_handle(int error, t_global *global)
{
	put_error(error);
	free_arguments(global);
    exit(error);
}
