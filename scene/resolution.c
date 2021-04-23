/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:48:41 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/22 21:27:19 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	split_free(char **str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		free(str[count]);
		count++;
	}
	free(str[count]);
	free(str);
}

int	check_num(char *str)
{
	if (!str)
		return (0);
	while (ft_isdigit(*str))
		str++;
	if (!*str)
		return (1);
	return (0);
}

void	create_res_more(t_global *global)
{
	if (abs(global->mlx_data.width) > MAX_X)
		global->mlx_data.width = MAX_X;
	if (abs(global->mlx_data.width) < MIN_X)
		global->mlx_data.width = MIN_X;
	if (abs(global->mlx_data.height) > MAX_Y)
		global->mlx_data.height = MAX_Y;
	if (abs(global->mlx_data.height) < MIN_Y)
		global->mlx_data.height = MIN_Y;
}

void	create_res(char *str, t_global *global)
{
	char	**line;

	line = ft_split(str + 2, ' ');
	if (!line)
		error_handle(ERROR_ALLOCATE, global);
	check_number_arg(line, 2, ERROR_RES, global);
	if (!line[0] || !line[1] || !check_num(line[0]) || !check_num(line[1]))
		error_handle(ERROR_RES, global);
	global->mlx_data.width = ft_atoi(line[0]);
	global->mlx_data.height = ft_atoi(line[1]);
	create_res_more(global);
	split_free(line);
}
