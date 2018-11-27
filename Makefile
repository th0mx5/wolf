# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/01 00:25:16 by thbernar          #+#    #+#              #
#    Updated: 2018/11/27 16:06:14 by maxisimo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = main.c \
	  fts_utils.c \
	  fts_utils2.c \
	  fts_raycasting.c \
	  fts_app.c \
	  fts_minimap.c \
	  fts_hook.c \
	  fts_draw.c \
	  fts_choose.c \
	  fts_move.c \
	  fts_weapons.c \
	  bmp_parser.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBMLX := -Lminilibx -lmlx
LIBFT := -Llibft -lft

LFT := libft/libft.a

FRAMEWORK := -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME) : $(OBJ) libft/libft.a minilibx/libmlx.a
	$(CC) $(LIBMLX) $(LIBFT) $(FRAMEWORK) $(OBJ) -o $(NAME)

libft/libft.a:
	make -C libft

minilibx/libmlx.a:
	make -C minilibx

clean: libft/libft.a minilibx/libmlx.a
	rm -rf $(OBJ) libft.a libmlx.a

fclean: clean libft/libft.a minilibx/libmlx.a
	rm -rf $(NAME)

re : fclean all
