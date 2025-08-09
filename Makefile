# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikhaing <0x@bontal.net>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/09 22:06:32 by mikhaing          #+#    #+#              #
#    Updated: 2025/08/09 22:08:19 by mikhaing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	main.c \
		string_utils.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c rush02.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re