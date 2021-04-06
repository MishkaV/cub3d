/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:05:53 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/06 12:13:18 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKS_MAP_H
# define CHECKS_MAP_H

void		check_first(char *str, t_global *global);
void        check_mid(char *str, t_global *global, t_list_map *list);
void        check_last(char *str, t_global *global, t_list_map *list);
#endif