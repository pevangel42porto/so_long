# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pevangel <pevangel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 12:08:34 by pevangel          #+#    #+#              #
#    Updated: 2024/04/10 17:58:15 by pevangel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH = lib/libft
LIBFT = $(LIBFT_PATH)/libft.a
MINILIBX_PATH = lib/mlx
MINILIBX = $(MINILIBX_PATH)/libmlx.a
PRINTF_PATH 	= 	lib/libft/ft_printf
PRINTF		= 	$(PRINTF_PATH)/libftprintf.a
HEADER = so_long.h
HEADERBONUS = bonus/so_long_bonus.h
CFLAGS = -Wall -Wextra -Werror -g
CFLAGS += -I/usr/include/X11
MLXFLAGS += -L/usr/X11/lib -lXext -lX11

SRC_FILES = so_long.c\
			exit_screen.c\
			map.c\
			is_valid_map.c\
			image.c\
			game_play.c\
			init_game.c\
			read_map.c\
			map_update.c\
			is_valid_map2.c
			
SRC_FILES_BONUS = bonus/so_long_bonus.c\
			bonus/exit_screen_bonus.c\
			bonus/map_bonus.c\
			bonus/is_valid_map_bonus.c\
			bonus/is_valid_map2_bonus.c\
			bonus/image_bonus.c\
			bonus/game_play_bonus.c\
			bonus/init_game_bonus.c\
			bonus/read_map_bonus.c\
			bonus/map_update_bonus.c

SOURCES = $(SRC_FILES)
SOURCES_BONUS = $(SRC_FILES_BONUS)

OBJECTS = $(SOURCES:.c=.o)
OBJECTSBONUS = $(SOURCES_BONUS:.c=.o)

NAME = so_long
NAMEBONUS = so_long_bonus
CC = cc
RM = rm -f

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

bonus: $(NAMEBONUS)
$(NAMEBONUS): $(LIBFT) $(MINILIBX) $(PRINTF) $(OBJECTSBONUS) $(HEADERBONUS)
	$(CC) $(CFLAGS) $(OBJECTSBONUS) $(LIBFT) $(MINILIBX) $(PRINTF) $(MLXFLAGS) -o $(NAMEBONUS)
clean:
			$(MAKE) -C $(LIBFT_PATH) clean
			$(MAKE) -C $(MINILIBX_PATH) clean
			$(MAKE) -C $(PRINTF_PATH) clean
			$(RM) $(OBJECTS)
			$(RM) $(OBJECTSBONUS)
fclean:		clean
			$(MAKE) -C $(LIBFT_PATH) fclean
			$(MAKE) -C $(PRINTF_PATH) fclean
			$(RM) $(NAME)
			$(RM) $(NAMEBONUS)
			
re:		fclean all

re_bounus:	fclean bonus

.PHONY: all clean fclean re bonus re_bonus libft minilibx printf
