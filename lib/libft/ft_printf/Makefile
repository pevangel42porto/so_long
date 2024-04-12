# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pevangel < pevangel@student.42porto.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 17:24:01 by pevangel          #+#    #+#              #
#    Updated: 2023/10/27 14:46:48 by pevangel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
flags = -Wall -Wextra -Werror
NAME  = libftprintf.a
SRC = ft_printf.c ft_format.c ft_putchar.c ft_putstr.c ft_ptr.c ft_hex_to_str.c \
		ft_putnbr.c ft_unsigned.c ft_hex.c
OBJS = *.o

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
$(OBJS): $(SRC)
	$(CC) $(flags) -c $(SRC)
clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all
