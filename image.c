/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevangel <pevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:57:46 by pevangel          #+#    #+#             */
/*   Updated: 2024/04/10 16:54:00 by pevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	width;
	int	heigth;

	game->img_w = mlx_xpm_file_to_image(game->mlx, "textures/W.xpm",
			&width, &heigth);
	game->img_bg = mlx_xpm_file_to_image(game->mlx, "textures/bg.xpm",
			&width, &heigth);
	game->img_c = mlx_xpm_file_to_image(game->mlx, "textures/C.xpm",
			&width, &heigth);
	game->img_e = mlx_xpm_file_to_image(game->mlx, "textures/E.xpm",
			&width, &heigth);
	game->img_p = mlx_xpm_file_to_image(game->mlx, "textures/P.xpm",
			&width, &heigth);
	if (game->img_w == NULL || game->img_bg == NULL || game->img_c == NULL
		|| game->img_e == NULL || game->img_p == NULL)
	{
		fprintf(stderr, "Erro ao carregar uma ou mais imagens.\n");
		exit(EXIT_FAILURE);
	}
}
