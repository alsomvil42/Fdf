# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 17:04:04 by alsomvil          #+#    #+#              #
#    Updated: 2018/04/26 01:31:33 by alsomvil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = fdf.c \

OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftfdf.a

all : $(NAME)

$(NAME): $(OBJ)
	ar rc fdf.a $(OBJ)
	make -C libft
	libtool libft/libft.a fdf.a -o $(NAME)
	rm -f ftprintf.a

%.o: %.c
	gcc $(FLAGS) -c -I include -I libft $^ -o $@

clean :
	make clean -C libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re norme
