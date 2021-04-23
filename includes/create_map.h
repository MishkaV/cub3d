/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 21:49:15 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/22 21:07:38 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_MAP_H
# define CREATE_MAP_H

void	make_array_map(t_list_map *list, t_global *global);
void	map_create(char *str, int file, t_global *global);

#endif