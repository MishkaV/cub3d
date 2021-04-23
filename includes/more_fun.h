/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_fun.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 21:01:57 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/22 21:14:46 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MORE_FUN_H
# define MORE_FUN_H

void	map_create_more(t_global *global, t_list_map *list);
int		map_create_read(char *str, int file,
			t_list_map *list, t_global *global);

#endif