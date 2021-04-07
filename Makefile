# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/08 16:05:20 by jbenjy            #+#    #+#              #
#    Updated: 2021/04/07 10:49:35 by jbenjy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= cub3D

DIR_SRCS		= ./srcs/

DIR_UTILS		= ./utils/

DIR_HEAD		= ./includes/

DIR_SCENE		= ./scene/

DIR_GNL			= ./gnl/

DIR_LIST		= ./list/

DIR_RAY			= ./raycasting/

SRCS			= $(DIR_SRCS)cub3d.c \
				$(DIR_UTILS)arg_checker.c \
				$(DIR_UTILS)checks_map.c \
				$(DIR_UTILS)load_texture.c \
				$(DIR_UTILS)inits.c \
				$(DIR_UTILS)press_key.c \
				$(DIR_SCENE)scene.c \
				$(DIR_SCENE)scene_utils.c \
				$(DIR_SCENE)resolution.c \
				$(DIR_SCENE)path.c \
				$(DIR_SCENE)create_map.c \
				$(DIR_SCENE)color.c \
				$(DIR_LIST)list.c \
				$(DIR_RAY)floor_ceil.c \
				$(DIR_RAY)throw_ray.c \
				$(DIR_GNL)get_next_line.c \
				$(DIR_GNL)get_next_line_utils.c \
				$(DIR_UTILS)errors.c

OBJS 			= $(SRCS:.c=.o)

CC 				= gcc
CFLAGS 			= -Wall -Wextra -Werror

MINILIBX 		=  libmlx.a
MINILIBX_FLAGS	=   -framework OpenGL -framework AppKit

L_MINILIBX		=  ./minilibx_opengl/libmlx.a 
L_LIBFT			=  ./libft/libft.a 

.c.o: 
	${CC} ${CFLAGS} -I ${DIR_HEAD} -c $< -o  $@

$(NAME): ${OBJS}
		make -C ./minilibx_opengl
		make -C ./libft
		${CC} ${CFLAGS} ${MINILIBX_FLAGS} -I ${DIR_HEAD} ${L_MINILIBX} ${L_LIBFT} ${OBJS} -o ${NAME} 

bonus: $(OBJS) 

all:	${NAME}

clean:
		$(MAKE) -C ./minilibx_opengl clean
		$(MAKE) -C ./libft clean
		rm -f $(OBJS)

fclean:	clean
		rm -f $(MINILIBX)
		rm -f ${NAME}

re:		fclean all
