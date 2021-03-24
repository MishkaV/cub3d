/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:04:08 by jbenjy            #+#    #+#             */
/*   Updated: 2021/03/24 17:24:17 by jbenjy           ###   ########.fr       */
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


void		put_error(int error);
int			cub_check(char *str);
void		error_handle(int error);
#endif
