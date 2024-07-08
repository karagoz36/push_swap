# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 14:16:36 by tkaragoz          #+#    #+#              #
#    Updated: 2024/06/20 14:52:50 by tkaragoz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = libft
LIBFT_TARGET = ${LIBFT}/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I${LIBFT} -g
LDFLAGS = -L${LIBFT} -lft
SRC_FILES = list.c main.c radix_s.c utils.c instructions_1.c \
			simple_s.c check.c simple_s_utils.c instructions_2.c
SRC = $(SRC_FILES)
OBJ = $(SRC:.c=.o)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT_TARGET)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

all: $(NAME)

$(LIBFT_TARGET):
	make -C $(LIBFT)

clean:
	make clean -C ${LIBFT}
	rm -f $(OBJ)

fclean: clean
	make fclean -C ${LIBFT}
	rm -f $(NAME)

re:fclean all

.PHONY: all clean fclean re