# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmounchi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/28 11:33:21 by mmounchi          #+#    #+#              #
#    Updated: 2019/01/13 16:41:43 by mmounchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Wextra -Werror -I libft

SRC = back.c cord.c main.c tab.c verif.c

OBJ = back.o cord.o main.o tab.o verif.o

LIBFT = libft/libft.a

all : $(NAME)

$(OBJ): %.o: %.c
		gcc -c $(CFLAGS) $< -o $@

$(LIBFT):
		make -C libft

$(NAME): $(LIBFT) $(OBJ)	
		gcc $(OBJ) $(LIBFT) -o $(NAME)

clean:
	rm -rf $(OBJ)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean

re: fclean all
