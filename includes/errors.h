/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:04:08 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/06 12:15:37 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERROR_ARG      1
# define ERROR_READ     2
# define ERROR_CONFIG   3
# define ERROR_ALLOCATE 4
# define ERROR_RES      5
# define ERROR_COLOR    6
# define ERROR_PATH     7
# define ERROR_MAP      8
# define ERROR_MAP_MID  9
# define ERROR_MAP_LAST 10


void		put_error(int error);
int			cub_check(char *str);
void		error_handle(int error, t_global *global);
#endif
