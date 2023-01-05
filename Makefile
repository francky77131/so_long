# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 14:20:55 by frgojard          #+#    #+#              #
#    Updated: 2023/01/04 17:38:04 by frgojard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =    so_long.c \
./utils/get_next_line.c \
./utils/get_next_line_utils.c \
./utils/split.c \
./utils/ft_strjoin.c \
./utils/ft_putnbr.c \
./utils/ft_putstr.c \
./utils/ft_putchar.c \
./utils/ft_strdup.c \
./parsing/check_collectible.c \
./parsing/check_exit.c \
./parsing/check_player.c \
./parsing/check_wall.c \
./parsing/check_shape.c \
./parsing/get_map.c \
./parsing/check_map.c \
./parsing/flood_fill.c \
./hook/hook.c \



OBJS = $(SRCS:.c=.o)

# /* ~~~~~~~ INCLUDING MINILIBX ~~~~~~~ */
MLX_DIR = mlx
MLX_MAKE = Makefile
MLX_PATH = ${MLX_DIR}/libmlx.a

# /* ~~~~~~~ COMPILING INFO ~~~~~~~ */
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iminilibx-linux
MFLAGS = $(MLX_PATH) -lXext -lX11

$(NAME): $(OBJS) $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MFLAGS)

$(MLX_PATH):
	make -C ${MLX_DIR}

all: ${NAME}

clean:
	make clean -C ${MLX_DIR}
	rm -f ${OBJS} ${B_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: bonus all clean fclean re