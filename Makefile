# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 17:35:41 by vsivanat          #+#    #+#              #
#    Updated: 2024/04/11 17:39:06 by vsivanat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast

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
	@if git submodule status | egrep -q '^[-+]' ; then \
		echo "INFO: Need to reinitialize git submodules"; \
		git submodule update --init; \
	fi
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

.PHONY: all clean fclean re libmlx libft



# NAME = fractol

# CC = cc
# CFLAGS = -Wall -Wextra -Werror -Ofast -g #-fsanitize=address

# MLXDIR = MLX42

# HEADER = -I ./ -I $(MLXDIR)/include -I ./lib/libft

# LIBS = $(MLXDIR)/build/libmlx42.a -ldl -lglfw -pthread -lm ./lib/libft/libft.a

# SRC = main.c \
# mandelbrot.c \
# julia.c \
# burningship.c \
# key_hook.c \
# color_picking.c \
# utils.c

# OBJ = $(SRC:.c=.o)

# all: libmlx libft $(NAME)

# libft: 
#     make -C ./lib/libft

# libmlx:
# 	@if git submodule status | egrep -q '^[-+]' ; then \
# 		echo "INFO: Need to reinitialize git submodules"; \
# 		git submodule update --init; \
# 	fi


# %.o: %.c
#     $(CC) $(CFLAGS) $(HEADER) -c $< -o $@

# $(NAME): $(OBJ)
#     $(CC) $(LDFLAGS) $(HEADER) $(OBJ) $(LIBS) -o $(NAME)

# clean:
#     make -C ./lib/libft clean
#     rm -f $(OBJ)
#     rm -rf $(MLXDIR)/build

# fclean: clean
#     make -C ./lib/libft fclean
#     rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re libmlx libft fractol $(NAME)
