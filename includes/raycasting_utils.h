/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:34:37 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/22 16:31:56 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_UTILS_H
# define RAYCASTING_UTILS_H

void	create_step(t_global *global);
void	create_raytracing(int x, t_global *global);
void	find_texture(t_global *global);
void	find_height(t_global *global);
void	find_ray(t_global *global);

#endif