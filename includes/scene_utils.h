/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:27:24 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/05 19:51:38 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_UTILS_H
# define SCENE_UTILS_H

int         check_insert_gl(t_global *global);
void        line_parse(char *str, t_global *global);
char		*trim_file(int fd);
void		map_create(char *str, int file);
#endif