# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/10 14:00:29 by jbenjy            #+#    #+#              #
#    Updated: 2020/11/11 16:54:19 by jbenjy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
						ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
						ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c \
						ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
						ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
						ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
						ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
						ft_putchar_fd.c  ft_putstr_fd.c ft_putendl_fd.c \
						ft_putnbr_fd.c
SRCS_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstmap.c ft_lstiter.c
OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCS_B:.c=.o)
HEADER = libft.h
CFLAGS = -Wall -Wextra -Werror

.c.o:
		gcc $(CFLAGS) -g -c $<

$(NAME): $(OBJS) $(HEADER)
		ar rcs $(NAME) ${OBJS}

bonus: $(OBJS) $(OBJSB)
		ar rcs $(NAME) $(OBJS) $(OBJSB)

all:	${NAME}

clean:
		rm -f $(OBJS) ${OBJSB}

fclean:	clean
		rm -f ${NAME}

re:		fclean all
