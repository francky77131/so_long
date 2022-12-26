# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 10:35:24 by frgojard          #+#    #+#              #
#    Updated: 2022/09/13 14:14:44 by frgojard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc -Wall -Werror -Wextra

RM = rm -f

SRC = 	ft_strncmp.c \
		ft_strlen.c  \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_atoi.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_memcmp.c \
		ft_strlcat.c \
		ft_memchr.c \
		ft_strnstr.c \
		ft_strdup.c \
		ft_calloc.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_itoa.c \
		ft_printf.c \
		ft_putstr.c \
		ft_putchar.c \
		ft_putnbr_count.c \
		ft_putnbr_hexa.c \
		ft_putnbr_u.c \
		ft_putnbr_p.c \
		get_next_line.c \
		get_next_line_utils.c \

BONUS_SRC = ft_lstnew_bonus.c \
            ft_lstadd_front_bonus.c \
            ft_lstsize_bonus.c \
            ft_lstlast_bonus.c \
            ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c


OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)
		
.c.o:
	$(CC) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) $(BONUS_OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
