/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:05:53 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/23 12:34:31 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKS_MAP_H
# define CHECKS_MAP_H

void	check_map_left_right(int i, t_global *global, char *map);
void	check_map_up_down(int i, t_global *global, char *map);
void	check_map_in_empty(int i, t_global *global, char *map);
void	check_map_sym(int i, t_global *global, char *map);
void	check_space_up(int i, int j, t_global *global);
void	check_space_down(int i, int j, t_global *global);
void	check_space_right(int i, int j, t_global *global);
void	check_space_left(int i, int j, t_global *global);
void	check_map(t_global *global);

#endif