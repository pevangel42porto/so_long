/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevangel <pevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:00:12 by pevangel          #+#    #+#             */
/*   Updated: 2024/04/10 17:00:13 by pevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(char **map)
{
	int	y;

	y = 1;
	if (!map[0])
		return (0);
	while (map[y])
	{
		if (ft_strlen(map[y]) != ft_strlen(map[0]))
			return (0);
		y++;
	}
	return (1);
}

static int	args_wall(int y, int x, int len, char **map)
{
	while (map[0][x])
	{
		if (map[0][x] != '1' || map[y - 1][x] != '1')
			return (0);
		x++;
	}
	y = 1;
	while (map[y])
	{
		len = ft_strlen(map[y]);
		if (len < 2 || map[y][0] != '1' || map[y][len - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	is_wall(char **map)
{
	int	y;
	int	x;
	int	len;

	y = 0;
	x = 0;
	len = 0;
	if (!map || !map[0] || !map[y])
		return (0);
	while (map[y])
		y++;
	if (y < 2)
		return (0);
	if (ft_strlen(map[0]) != ft_strlen(map[y - 1]))
		return (0);
	if (!args_wall(y, x, len, map))
		return (0);
	return (1);
}

static void	args_correct(int y, int x, t_game *game)
{
	if (game->map[y][x] == 'P')
	{
		game->n_player++;
		game->y_player = y;
		game->x_player = x;
		game->map[y][x] = '0';
	}
	else if (game->map[y][x] == 'C')
		game->n_collectable++;
	else if (game->map[y][x] == 'E')
		game->n_exit++;
}

int	is_correct_arguments(t_game *game)
{
	int	y;
	int	x;

	game->n_player = 0;
	game->n_collectable = 0;
	game->n_exit = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			args_correct(y, x, game);
			x++;
		}
		y++;
	}
	if (game->n_player == 1 && game->n_collectable >= 1 && game->n_exit == 1)
		return (1);
	return (0);
}
