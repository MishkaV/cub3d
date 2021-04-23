/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 22:48:35 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/22 16:29:15 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

t_list_map	*new_node_map(char *data);
t_list_map	*push_back_map(t_list_map *root, char *data);
void		free_list_map(t_list_map *root);
void		max_len(t_list_map *root, t_global *global);
void		count_node(t_list_map *root, t_global *global);

#endif