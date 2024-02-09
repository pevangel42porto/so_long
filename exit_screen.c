
#include "so_long.h"

/* int display_confirmation_message(int event, t_game *game)
{
    int win_width, win_height;
    mlx_get_screen_size(game->mlx, &win_width, &win_height);

    // Centraliza a mensagem na tela
   // int text_width = 800; // Largura estimada do texto
    //int text_height = 400; // Altura estimada do texto
    int x = 725;//(win_width - text_width) / 2;
    int y = 10;//(win_height - text_height) / 2;

    mlx_string_put(game->mlx, game->win, x, y, 0xFFFFFF, "Deseja realmente sair? sim -> Y | nao -> N");
    if ((event == 'y' || event == 'Y') && game->exit_confirmation == 1)
    {
        mlx_destroy_window(game->mlx, game->win);
        exit(EXIT_SUCCESS);
    }
    else if ((event == 'n' || event == 'N') && game->exit_confirmation == 1)
    {
        clear_confirmation_message(game);
        game->exit_confirmation = 0;
    }
    return (0);
}
 */
void clear_confirmation_message(t_game *game)
{
    mlx_clear_window(game->mlx, game->win);
}


int handleWindowClose(t_game *game)
{
    ft_printf("Window closed.\n");
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
    return 0;
}
