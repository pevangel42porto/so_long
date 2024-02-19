/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevangel < pevangel@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:08:29 by pevangel          #+#    #+#             */
/*   Updated: 2024/01/24 12:21:07 by pevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include "libraries/mlx/mlx.h"
# include "libraries/mlx/mlx_int.h"
# include "libraries/libft/libft.h"
# include "libraries/libft/ft_printf/ft_printf.h"

#define TILE_SIZE 40 // Tamanho das imagens 
#define MAP_HEIGHT 9
#define MAP_WIDTH 25

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		next_y;
	int		next_x;
	int		x_player;
	int		y_player;
	int		score;
	int		moves;
	int		endgame;
	int		color;
	int		exit_confirmation;

// Imagens
	void	*image_wall;
	void	*image_empty;
	void	*image_collectible;
	void	*image_exit;
	void	*image_player;
}	t_game;


int			handleWindowClose(t_game *game);

#endif
