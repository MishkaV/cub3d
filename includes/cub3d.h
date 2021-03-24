/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:00:29 by mishavorozh       #+#    #+#             */
/*   Updated: 2021/03/24 17:26:49 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx_opengl/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct  s_vector
{
    int         x;
    int         y;
}               t_vector;

typedef struct  s_scene
{
    t_vector    res;
    int         color_floor;
    int         color_ceil;
    char        *path_west;
    char        *path_east;
    char        *path_north;
    char        *path_south;
    char        *path_sprite;
}               t_scene;

typedef struct  s_global
{
    t_scene     scene;
}               t_global;

# include "../gnl/get_next_line.h" 
# include "errors.h"
# include "arg_checker.h"
# include "scene.h"
# include "vector.h"
# include "resolution.h"
# include "color.h" 
# include "path.h"
#endif