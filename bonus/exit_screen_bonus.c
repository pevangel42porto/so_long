/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_screen_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevangel <pevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:58:59 by pevangel          #+#    #+#             */
/*   Updated: 2024/04/10 19:09:45 by pevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	i = 0;
	if (game->map_path)
	{
		while (game->map_path[i])
		{
			free(game->map_path[i]);
			i++;
		}
		free(game->map_path);
	}
}

int	handle_window_close(t_game *game)
{
	ft_printf("Window closed.\n");
	mlx_destroy_image(game->mlx, game->img_p);
	mlx_destroy_image(game->mlx, game->img_w);
	mlx_destroy_image(game->mlx, game->img_bg);
	mlx_destroy_image(game->mlx, game->img_e);
	mlx_destroy_image(game->mlx, game->img_c);
	mlx_destroy_image(game->mlx, game->img_pr);
	mlx_destroy_image(game->mlx, game->img_pl);
	mlx_destroy_image(game->mlx, game->img_pu);
	mlx_destroy_image(game->mlx, game->img_pd);
	mlx_destroy_image(game->mlx, game->img_dead);
	mlx_destroy_image(game->mlx, game->img_emy);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game);
	exit(0);
	return (0);
}
