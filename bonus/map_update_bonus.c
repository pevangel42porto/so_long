/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevangel <pevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:59:30 by pevangel          #+#    #+#             */
/*   Updated: 2024/04/12 13:21:37 by pevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	player_update_image(char key, t_game *game)
{
	if (key == 'w')
		img_draw(game, game->img_pu, game->x_player, game->y_player);
	else if (key == 's')
		img_draw(game, game->img_pd, game->x_player, game->y_player);
	else if (key == 'd')
		img_draw(game, game->img_pr, game->x_player, game->y_player);
	else if (key == 'a')
		img_draw(game, game->img_pl, game->x_player, game->y_player);
}

static void	update_move(int keycode, t_game *game, int void_me)
{
	(void) void_me;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	if (game->map[game->y_player][game->x_player] == 'C')
	{
		game->n_collectable--;
		game->score++;
		game->map[game->y_player][game->x_player] = '0';
	}
	else if (game->map[game->y_player][game->x_player] == 'E'
		&& game->n_collectable == 0)
	{
		handle_window_close(game);
	}
	map_draw(game);
	player_update_image(keycode, game);
}

static int	is_valid_move(int x, int y, t_game *game)
{
	if (game->map[y][x] == '0' || game->map[y][x] == 'C'
		|| game->map[y][x] == 'E')
		return (1);
	else if (game->map[y][x] == 'N')
	{
		game->moves++;
		map_draw(game);
		img_draw(game, game->img_dead, game->x_player, game->y_player);
		game->endgame = 1;
	}
	return (0);
}

void	move(int keycode, t_game *game)
{
	if (keycode == 65361 || keycode == 'a')
	{
		if (is_valid_move(game->x_player - 1, game->y_player, game))
			update_move(keycode, game, game->x_player--);
	}
	else if (keycode == 65363 || keycode == 'd')
	{
		if (is_valid_move(game->x_player + 1, game->y_player, game))
			update_move(keycode, game, game->x_player++);
	}
	else if (keycode == 65362 || keycode == 'w')
	{
		if (is_valid_move(game->x_player, game->y_player - 1, game))
			update_move(keycode, game, game->y_player--);
	}
	else if (keycode == 65364 || keycode == 's')
	{
		if (is_valid_move(game->x_player, game->y_player + 1, game))
			update_move(keycode, game, game->y_player++);
	}
}
