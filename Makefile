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

SRC = main.c \

OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = fdf

all : $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C minilibx
	gcc -o $(NAME) $(OBJ) libft/libft.a minilibx/libmlx.a -lX11 -lXext

%.o: src/%.c
	gcc -c -I include -I libft -I minilibx $^ -o $@
	

clean :
	make clean -C libft
	rm -rf *.o 

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re norme
