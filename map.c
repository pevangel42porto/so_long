/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevangel <pevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:58:14 by pevangel          #+#    #+#             */
/*   Updated: 2024/04/10 17:08:19 by pevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_draw(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, image,
		x * game->tile_size, y * game->tile_size);
}

int	map_draw(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				img_draw(game, game->img_w, x, y);
			else if (game->map[y][x] == '0')
				img_draw(game, game->img_bg, x, y);
			else if (game->map[y][x] == 'C')
				img_draw(game, game->img_c, x, y);
			else if (game->map[y][x] == 'E')
				img_draw(game, game->img_e, x, y);
			x++;
		}
		y++;
	}
	img_draw(game, game->img_p, game->x_player, game->y_player);
	return (0);
}
