# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/05 17:28:06 by mikhaing          #+#    #+#              #
#    Updated: 2025/08/05 17:28:09 by mikhaing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_display_file
CC=cc
CFLAGS=-Wall -Wextra -Werror
SRC=ft_display_file.c
OBJ=$(SRC:.c=.o)

all: $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re