/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevangel <pevangel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:59:58 by pevangel          #+#    #+#             */
/*   Updated: 2024/04/10 18:20:48 by pevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include "../lib/mlx/mlx.h"
# include "../lib/mlx/mlx_int.h"
# include "../lib/libft/libft.h"
# include "../lib/libft/ft_printf/ft_printf.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	char	**map_path;
	int		map_h;
	int		map_w;
	int		tile_size;
	int		x_player;
	int		y_player;
	int		score;
	int		moves;
	int		endgame;
	int		color;
	int		image_heigth;
	int		image_width;
	int		n_player;
	int		n_collectable;
	int		n_exit;
	int		n_enemy;
	void	*img_w;
	void	*img_bg;
	void	*img_c;
	void	*img_e;
	void	*img_p;
	void	*img_emy;
	void	*img_pu;
	void	*img_pd;
	void	*img_pl;
	void	*img_pr;
	void	*img_dead;
}	t_game;

int			handle_window_close(t_game *game);
void		load_images(t_game *game);
int			map_checker(t_game *game);
int			key_release(t_game *game);
void		init_game(t_game *game);
char		**read_map(char *path);
int			map_draw(t_game *game);
void		game_play(t_game *game);
void		move(int keycode, t_game *game);
void		free_map(t_game *game);
int			handleWindowClose(t_game *game);
void		img_draw(t_game *game, void *image, int x, int y);
void		error(char *str);
int			is_rectangular(char **map);
int			is_wall(char **map);
int			is_correct_arguments(t_game *game);

#endif
