# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 17:04:04 by alsomvil          #+#    #+#              #
#    Updated: 2018/05/18 01:52:59 by alsomvil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
	  ft_setsegment.c \
	  get_next_line.c \
	  deal_key.c \
	  ft_setsegment_rotate.c \

OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = fdf

all : $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc $(FLAGS) -I /usr/local/include *.c libft/*.a -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	gcc $(FLAGS) -c -I include -I libft -I minilibx $^ -o $@

clean :
	make clean -C libft
	rm -rf *.o 

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re norme
