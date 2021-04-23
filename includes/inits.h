/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:00:43 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/22 21:55:47 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITS_H
# define INITS_H

void	init_vectors(char c, t_global *global, int i, int j);
void	init_global(t_global *global);
void	init_player(t_global *global);
void	inits_sprites(t_global *global);

#endif