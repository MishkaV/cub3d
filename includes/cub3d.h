/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:25:26 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/06 21:33:15 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H
# define PI 3.14159265

# include "../libft/libft.h"
# include "../minilibx_opengl/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct  s_list_map
{
    char        *data;
    void        *next;
}               t_list_map;

typedef struct  s_map
{
    char        *data;
    int         width;
    int         height;
}               t_map;


typedef struct  s_mlx_data
{
    void        *mlx;
    void        *window;
    int         width;
    int         height;
    t_map       map;
}               t_mlx_data;

typedef struct  s_picture
{
    void        *ptr;
    char        *data;
    char        *directory;
    int         bpp;
    int         size_line;
    int         endine;
}               t_picture;

typedef struct  s_scene
{
    int         color_floor;
    int         color_ceil;
    t_picture   path_west;
    t_picture   path_east;
    t_picture   path_north;
    t_picture   path_south;
    t_picture   path_sprite;
}               t_scene;

typedef struct  s_player
{
    double      x_pos;
    double      y_pos;
    double      x_direct;
    double      y_direct;
    double      x_plane;
    double      y_plane;
}               t_player;


typedef struct  s_global
{
    t_mlx_data  mlx_data;
    t_scene     scene;
    t_picture   main_image;
    t_player    player;
}               t_global;


# include "list.h"
# include "../gnl/get_next_line.h" 
# include "errors.h"
# include "arg_checker.h"
# include "scene.h"
# include "resolution.h"
# include "color.h" 
# include "path.h"
# include "scene_utils.h"
# include "create_map.h"
# include "checks_map.h"
# include "throw_ray.h"
# include "floor_ceil.h"
# include "inits.h"
# include "load_texture.h"
#endif