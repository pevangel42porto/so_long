/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevangel <pevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:59:25 by pevangel          #+#    #+#             */
/*   Updated: 2024/04/10 19:11:30 by pevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	img_draw(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, image,
		x * game->tile_size, y * game->tile_size);
}

static void	update_moves_display(t_game *game)
{
	char	moves_text[20];
	char	*str;

	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 85, 10, 0xFFFFFF, "Moves:");
	ft_strlcpy(moves_text, str, sizeof(moves_text));
	mlx_string_put(game->mlx, game->win, 130, 10, 0xFFFFFF, moves_text);
	free(str);
}

static void	update_score_display(t_game *game)
{
	char	score_text[20];
	char	*str;

	str = ft_itoa(game->score);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, "Score:");
	ft_strlcpy(score_text, str, sizeof(score_text));
	mlx_string_put(game->mlx, game->win, 60, 10, 0xFFFFFF, score_text);
	free(str);
}

int	map_draw(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '1')
				img_draw(game, game->img_w, x, y);
			else if (game->map[y][x] == '0')
				img_draw(game, game->img_bg, x, y);
			else if (game->map[y][x] == 'C')
				img_draw(game, game->img_c, x, y);
			else if (game->map[y][x] == 'E')
				img_draw(game, game->img_e, x, y);
			else if (game->map[y][x] == 'N')
				img_draw(game, game->img_emy, x, y);
		}
	}
	img_draw(game, game->img_p, game->x_player, game->y_player);
	update_moves_display(game);
	update_score_display(game);
	return (0);
}
