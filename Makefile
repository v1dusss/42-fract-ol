# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 17:35:41 by vsivanat          #+#    #+#              #
#    Updated: 2024/04/09 17:04:15 by vsivanat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLXDIR = ./lib/mlx-42

HEADER = -I ./ -I $(MLXDIR)/include -I ./lib/libft

LIBS = $(MLXDIR)/build/libmlx42.a -ldl -lglfw -pthread -lm ./lib/libft/libft.a

SRC = main.c \
mandelbrot.c \
julia.c \
burningship.c \
key_hook.c \
color_picking.c \
utils.c

OBJ = $(SRC:.c=.o)

all: libmlx libft $(NAME)

libft: 
	make -C ./lib/libft

libmlx:
	cmake $(MLXDIR) -B $(MLXDIR)/build
	make -C $(MLXDIR)/build -j4

%.o: %.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(HEADER) $(OBJ) $(LIBS) -o $(NAME)

clean:
	make -C ./lib/libft clean
	rm -f $(OBJ)
	rm -rf $(MLXDIR)/build

fclean: clean
	make -C ./lib/libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx libft fractol $(NAME)
