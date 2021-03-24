/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:07:05 by jbenjy            #+#    #+#             */
/*   Updated: 2021/03/24 17:25:14 by jbenjy           ###   ########.fr       */
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

}


int			cub_check(char *str)
{
	int len;

	len = ft_strlen(str);
	if (len < 5)
		return (0);
	if(!ft_strncmp(str + len - 4, ".cub", 5))
		return (1);
	return (0);
}

void		error_handle(int error)
{
	put_error(error);
    exit(error);
}