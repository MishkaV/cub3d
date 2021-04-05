/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:25:26 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/05 21:50:03 by jbenjy           ###   ########.fr       */
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

typedef struct  s_map
{
    char        *map;
    int         width;
    int         height;
}               t_map;


typedef struct  s_mlx_data
{
    void        *mlx;
    void        *window;
    int         width;
    int         height;
    char        *map;
}               t_mlx_data;

typedef struct  s_image
{
    void        *ptr;
    char        *data;
    char        *directory;
    int         bpp;
    int         size_line;
    int         endine;
}               t_image;

typedef struct  s_scene
{
    int         color_floor;
    int         color_ceil;
    t_image     path_west;
    t_image     path_east;
    t_image     path_north;
    t_image     path_south;
    t_image     path_sprite;
}               t_scene;

typedef struct  s_global
{
    t_mlx_data  mlx_data;
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
# include "scene_utils.h"
# include "create_map.h"
#endif