/* ************************************************************************** */
/*				 */
/*						   :::	 ::::::::   */
/*   so_long.c							:+:	 :+:	:+:   */
/*					  +:+ +:+		 +:+	*/
/*   By: pevangel <pevangel@student.42.fr>		  +#+  +:+	  +#+		*/
/*				   +#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/24 12:08:21 by pevangel		  #+#	#+#			 */
/*   Updated: 2024/04/10 15:36:35 by pevangel		 ###   ########.fr	  */
/*				 */
/* ************************************************************************** */

#include "so_long.h"

static int	argv_checker(char *argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == 'r' && argv[i - 1] == 'e' && argv[i - 2] == 'b'
		&& argv [i - 3] == '.')
		return (1);
	return (0);
}

void	error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		if (!argv_checker(argv[1]))
			error("Invalid Map");
		game.map = read_map(argv[1]);
		game.map_path = read_map(argv[1]);
		if (map_checker(&game))
		{
			init_game(&game);
			game_play(&game);
			mlx_loop(game.mlx);
		}
		else
		{
			if (game.map && game.map_path)
				free_map(&game);
			error("Invalid Map");
		}
	}
	else
		error("Error: ./so_long <map.ber>");
	return (0);
}
