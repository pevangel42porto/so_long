/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevangel <pevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:59:04 by pevangel          #+#    #+#             */
/*   Updated: 2024/04/10 18:06:26 by pevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	game_events(int keycode, t_game *game)
{
	if (keycode == 'w' || keycode == 65362)
		move('w', game);
	else if (keycode == 's' || keycode == 65364)
		move('s', game);
	else if (keycode == 'a' || keycode == 65361)
		move('a', game);
	else if (keycode == 'd' || keycode == 65363)
		move('d', game);
}

static int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307 || keycode == 'q')
	{
		handle_window_close(game);
	}
	else if (!game->endgame)
	{
		game_events(keycode, game);
	}
	return (0);
}

void	game_play(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 17, 1L << 17, handle_window_close, game);
}
