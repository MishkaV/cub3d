/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:25:54 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/22 20:04:53 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_UTILS_H
# define SPRITES_UTILS_H

void	parse_list(t_global *global, t_sprite *list, int *range, int len_list);
void	buble_sort_list(t_sprite *list, int *range, int len_list);
void	calculate_sprite(t_global *global, t_sprite *sprite, t_var_sprite *var);
void	more_calculation(t_global *global, t_var_sprite *var);
void	paint_texture(t_global *global, int i, int j, t_var_sprite *var);

#endif