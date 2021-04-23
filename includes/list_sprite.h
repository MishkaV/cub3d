/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sprite.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:45:47 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/22 16:28:38 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_SPRITE_H
# define LIST_SPRITE_H

t_list_sprite	*new_node_sprite(t_sprite *data);
t_list_sprite	*push_back_sprite(t_list_sprite *root, t_sprite *data);
void			free_list_sprite(t_list_sprite *root);
int				count_node_sprite(t_list_sprite *root);

#endif