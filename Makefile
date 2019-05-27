# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 17:04:04 by alsomvil          #+#    #+#              #
#    Updated: 2018/07/03 01:21:15 by alsomvil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
	  create_tab.c \
	  deal_key.c \
	  ft_rotate.c \
	  ft_bresenham.c \
	  ft_create_tab_int.c \
	  ft_pasdeplace.c

MLX = -L /usr/local/lib/ -lmlx -framework OpenGl -framework Appkit
OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS =  -Wall -Wextra -Werror
NAME = fdf
_GREEN = $ \033[32m
_YELLOW = $ \033[33m
_RED = $ \033[31m
_END = $ \033[0m

all : $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@gcc $(CFLAGS) -o $(NAME) -I /usr/local/include/ $(OBJ) libft/libft.a $(MLX)
	@echo "$(_GREEN)fdf compiled$(_END)"

%.o: %.c
	@$(CC) -c $(CFLAGS) -I. $< -o $@

clean:
	@$(MAKE) clean -C libft
	@rm -f $(OBJ)
	@echo "libft cleaned"
	@echo "fdf cleaned"

fclean: clean
	@$(MAKE) fclean -C libft
	@rm -f $(NAME)
	@echo "fdf fcleaned"

re: fclean all

.PHONY: libft clean fclean all re
