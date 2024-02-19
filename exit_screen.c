
#include "so_long.h"



int handleWindowClose(t_game *game)
{
    ft_printf("Window closed.\n");
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
    return 0;
}
