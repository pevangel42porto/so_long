# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pevangel < pevangel@student.42porto.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 12:08:34 by pevangel          #+#    #+#              #
#    Updated: 2024/01/24 12:54:13 by pevangel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH = libraries/libft
LIBFT = $(LIBFT_PATH)/libft.a
MINILIBX_PATH = libraries/mlx
MINILIBX = $(MINILIBX_PATH)/libmlx.a
PRINTF_PATH 	= 	libraries/libft/ft_printf
PRINTF		= 	$(PRINTF_PATH)/libftprintf.a
SRC_FILES = so_long.c exit_screen.c
HEADER = so_long.h

SOURCES = $(SRC_FILES)

OBJECTS = $(SOURCES:.c=.o)
NAME = so_long
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L. -lXext -L. -lX11
.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
all: $(NAME)
$(NAME): $(LIBFT) $(MINILIBX) $(PRINTF) $(OBJECTS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MINILIBX) $(PRINTF) $(MLXFLAGS) -o $(NAME)
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)
$(MINILIBX):
	$(MAKE) -C $(MINILIBX_PATH)
$(PRINTF):
	$(MAKE) -C $(PRINTF_PATH)
clean:
			$(MAKE) -C $(LIBFT_PATH) clean
			$(MAKE) -C $(MINILIBX_PATH) clean
			$(MAKE) -C $(PRINTF_PATH) clean
			$(RM) $(OBJECTS)
fclean:		clean
			$(MAKE) -C $(LIBFT_PATH) fclean
			$(MAKE) -C $(PRINTF_PATH) fclean
			$(RM) $(NAME)
re:		fclean all
.PHONY:		all clean fclean re libft minilibx printf
