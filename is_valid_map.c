/* ************************************************************************** */
/*							*/
/*						:::	  ::::::::   */
/*   is_valid_map_bonus.c							   :+:	  :+:	:+:   */
/*					+:+ +:+		 +:+	 */
/*   By: pevangel <pevangel@student.42.fr>		  +#+  +:+	   +#+		*/
/*				+#+#+#+#+#+   +#+		   */
/*   Created: 2024/04/10 11:59:20 by pevangel		  #+#	#+#			 */
/*   Updated: 2024/04/10 15:22:13 by pevangel		 ###   ########.fr	   */
/*							*/
/* ************************************************************************** */

#include "so_long.h"

static int	only_accept_wepecn(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == '1' || game->map[y][x] == '0'
				|| game->map[y][x] == 'P' || game->map[y][x] == 'E'
				|| game->map[y][x] == 'C')
			{
				x++;
			}
			else
				return (0);
		}
		y++;
	}
	return (1);
}

static void	flood_fill(char **map, int i, int j)
{
	if (map[i][j] == '1' || map[i][j] == 'F')
		return ;
	map[i][j] = 'F';
	flood_fill(map, i + 1, j);
	flood_fill(map, i - 1, j);
	flood_fill(map, i, j + 1);
	flood_fill(map, i, j - 1);
}

static int	flood_check(t_game *game)
{
	int	y;
	int	x;

	flood_fill(game->map_path, game->y_player, game->x_player);
	y = 0;
	while (game->map_path[y])
	{
		x = 0;
		while (game->map_path[y][x] != '\0')
		{
			if (game->map_path[y][x] == '0' || game->map_path[y][x] == 'E'
				|| game->map_path[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	map_checker(t_game *game)
{
	if (is_rectangular(game->map) && is_wall(game->map)
		&& is_correct_arguments(game) && only_accept_wepecn(game)
		&& flood_check(game))
		return (1);
	return (0);
}
