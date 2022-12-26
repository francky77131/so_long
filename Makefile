# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 14:20:55 by frgojard          #+#    #+#              #
#    Updated: 2022/12/21 18:58:26 by frgojard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =    so_long.c \


OBJS = $(SRCS:.c=.o)

# /* ~~~~~~~ INCLUDING MINILIBX ~~~~~~~ */
MLX_DIR = minilibx-linux
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