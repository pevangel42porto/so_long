/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevangel <pevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:59:14 by pevangel          #+#    #+#             */
/*   Updated: 2024/04/10 18:14:47 by pevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	size_window_init(t_game *game)
{
	int	i;

	game->tile_size = 40;
	game->map_w = ft_strlen(game->map[0]) * game->tile_size;
	i = 0;
	while (game->map[i])
		i++;
	game->map_h = i * game->tile_size;
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	size_window_init(game);
	game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, "so_long");
	game->color = 0xFF0000;
	game->score = 0;
	game->moves = 0;
	game->endgame = 0;
	load_images(game);
	map_draw(game);
}
