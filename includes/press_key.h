/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 10:33:27 by mishavorozh       #+#    #+#             */
/*   Updated: 2021/04/23 13:10:05 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESS_KEY_H
# define PRESS_KEY_H

void	change_position(double value1, double value2,
			int mode, t_global *global);
int		press_key(int key, t_global *global);
int		press_close(t_global *global);
void	end_game(t_global *global, int error);

#endif