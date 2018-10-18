# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thbernar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/01 00:25:16 by thbernar          #+#    #+#              #
#    Updated: 2018/10/18 16:00:27 by maxisimo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = main.c \
	  fts_utils.c \
	  fts_raycasting.c \
	  fts_app.c \
	  fts_minimap.c \
	  fts_collisions.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	make -C minilibx
	mv libft/libft.a .
	mv minilibx/libmlx.a .
	gcc -Wall -g -Werror -Wextra -c $(SRC)
	gcc -Wall -g -Werror -Wextra -L. -lmlx -lft -framework OpenGL -framework Appkit $(OBJ) -o $(NAME)

clean:
	make -C libft clean
	make -C minilibx clean
	rm -rf $(OBJ) libft.a libmlx.a

fclean: clean
	make -C libft fclean
	make -C minilibx clean
	rm -rf $(NAME)

re : fclean all
