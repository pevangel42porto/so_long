/* ************************************************************************** */
/*			*/
/*			:::	  ::::::::   */
/*   image_bonus.c		  :+:	  :+:	:+:   */
/*			+:+ +:+	 +:+	 */
/*   By: pevangel <pevangel@student.42.fr>	  +#+  +:+	   +#+	*/
/*		+#+#+#+#+#+   +#+	   */
/*   Created: 2024/04/10 11:59:09 by pevangel	  #+#	#+#		 */
/*   Updated: 2024/04/10 17:52:45 by pevangel	 ###   ########.fr	   */
/*			*/
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_images2(int width, int heigth, t_game *game)
{
	game->img_pu = mlx_xpm_file_to_image(game->mlx, "textures/P_U.xpm",
			&width, &heigth);
	game->img_pd = mlx_xpm_file_to_image(game->mlx, "textures/P_D.xpm",
			&width, &heigth);
	game->img_pl = mlx_xpm_file_to_image(game->mlx, "textures/P_L.xpm",
			&width, &heigth);
	game->img_pr = mlx_xpm_file_to_image(game->mlx, "textures/P.xpm",
			&width, &heigth);
	game->img_dead = mlx_xpm_file_to_image(game->mlx, "textures/N.xpm",
			&width, &heigth);
	game->img_emy = mlx_xpm_file_to_image(game->mlx, "textures/Emy.xpm",
			&width, &heigth);
}

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
	load_images2(width, heigth, game);
	if (game->img_w == NULL || game->img_bg == NULL || game->img_c == NULL
		|| game->img_e == NULL || game->img_p == NULL || game->img_pu == NULL
		|| game->img_pd == NULL || game->img_pl == NULL || game->img_pr == NULL
		|| game->img_dead == NULL || game->img_emy == NULL)
	{
		fprintf(stderr, "Erro ao carregar uma ou mais imagens.\n");
		exit(EXIT_FAILURE);
	}
}
