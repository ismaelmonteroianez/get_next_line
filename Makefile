# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismonter <ismonter@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/08 16:26:58 by ismonter          #+#    #+#              #
#    Updated: 2026/02/08 16:28:05 by ismonter         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
SOURCE = \
	get_next_line.c \
	get_next_line_utils.c
OBJS = $(SOURCE:.c=.o)

CFLAGS = -Wall -Wextra -Werror
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c libft.h
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all