/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:36:37 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/06 21:40:39 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LOAD_TEXTURE_H
# define LOAD_TEXTURE_H

void    create_texture(t_global *global, t_mlx_data *mlx_data, t_picture *image, char *name);
void    init_texture(t_global *global);

#endif