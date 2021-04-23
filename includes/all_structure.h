/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_structure.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:23:37 by jbenjy            #+#    #+#             */
/*   Updated: 2021/04/23 13:08:41 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_STRUCTURE_H
# define ALL_STRUCTURE_H

typedef struct s_list_map
{
	char	*data;
	void	*next;
}	t_list_map;

typedef struct s_map
{
	char	*data;
	int		width;
	int		height;
}	t_map;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	t_map	map;
}	t_mlx_data;

typedef struct s_picture
{
	void	*ptr;
	char	*data;
	char	*directory;
	int		bpp;
	int		size_line;
	int		endine;
}	t_picture;

typedef struct s_scene
{
	int			color_floor;
	int			color_ceil;
	t_picture	path_west;
	t_picture	path_east;
	t_picture	path_north;
	t_picture	path_south;
	t_picture	path_sprite;
}	t_scene;

typedef struct s_player
{
	double	x_pos;
	double	y_pos;
	double	x_direct;
	double	y_direct;
	double	x_plane;
	double	y_plane;
}	t_player;

typedef struct s_raytrace
{
	int			side;
	double		vector;		
	double		x_ray;
	double		y_ray;
	double		x_delta;
	double		y_delta;
	double		x_step;
	double		y_step;
	int			x_map;
	int			col_height;
	int			y_map;
	double		x_s;
	double		y_s;
	double		height_wall;
	t_picture	*texture;
}	t_raytrace;

typedef struct s_sprite
{
	int	x;
	int	y;
}	t_sprite;

typedef struct s_list_sprite
{
	t_sprite	sprite;
	void		*next;
}	t_list_sprite;

typedef struct s_list_dist
{
	double	*list_dist;
	int		curr;
}	t_list_dist;

typedef struct s_var_sprite
{
	double	mult_const;
	double	x_cast;
	double	y_cast;
	double	dist;
	int		middle;
	int		x_launch;
	int		y_launch;
	int		x_finish;
	int		y_finish;
}	t_var_sprite;

typedef struct s_global
{
	t_mlx_data		mlx_data;
	t_scene			scene;
	t_picture		main_image;
	t_player		player;
	t_raytrace		raytrace;
	t_list_sprite	*list_sprite;
	t_list_dist		list_dist;
	int				check_bmp;
}	t_global;

#endif