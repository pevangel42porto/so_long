/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevangel < pevangel@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:08:21 by pevangel          #+#    #+#             */
/*   Updated: 2024/01/24 13:51:04 by pevangel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int are_collectables_remaining(t_game *game)
{
    int i = 0;
    int j = 0;
    while (i < MAP_HEIGHT)
    {
        while(j < MAP_WIDTH)
        {
            if (game->map[i][j] == 'C')
            {
                return (1); // Ainda há coletáveis restantes
            }
            j++;
        }
        i++;
        j = 0;
    }
    return (0); // Não há mais coletáveis
}

/* void update_moves_display(t_game *game)
{
    mlx_string_put(game->mlx, game->win, 85, 10, 0xFFFFFF, "Moves:");
    char movesText[20];
    ft_strlcpy(movesText, ft_itoa(game->moves), sizeof(movesText));
    mlx_string_put(game->mlx, game->win, 100, 10, 0xFFFFFF, movesText);
}


void	update_score_display(t_game *game)
{
    mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, "Score:");
    char scoreText[20];
    ft_strlcpy(scoreText, ft_itoa(game->score), sizeof(scoreText));
    mlx_string_put(game->mlx, game->win, 60, 10, 0xFFFFFF, scoreText);
} */

void	collect_collectable(t_game *game, int x, int y)
{
    if (game->map[y / TILE_SIZE][x / TILE_SIZE] == 'C')
    {
        // Remova o coletável do mapa (substituindo por '0')
        game->map[y / TILE_SIZE][x / TILE_SIZE] = '0';
        // Adicione lógica para aumentar a pontuação ou fazer outras ações necessárias
        game->score += 10; // Adiciona 10 à pontuação por coletável
        // Exibe a pontuação na janela do jogo
       // update_score_display(game);
    }
}

 int is_valid_move(t_game *game, int x_player, int y_player)
{
    int next_y = y_player;
    int next_x = x_player;

    int i = next_y / TILE_SIZE;
    int j = next_x / TILE_SIZE;
    char cell;

    if (i >= 0 && i < MAP_HEIGHT && j >= 0 && j < MAP_WIDTH)
    {
        cell = game->map[i][j];
        if (cell == '0' || cell == 'P' || cell == 'C' || cell == 'E')
            return 1;
    }
    return 0;
}


int key_press(int keycode, t_game *game)
{
    printf("Tecla pressionada: %d\n", keycode);

    int next_x = game->x_player;
    int next_y = game->y_player;
    
    if (keycode == 65361 || keycode == 'a') // Tecla para a esquerda
        next_x -= TILE_SIZE;
    else if (keycode == 65363 || keycode == 'd') //Tecla para a direita
        next_x += TILE_SIZE;
    else if (keycode == 65362 || keycode == 'w') //Tecla para cima
        next_y -= TILE_SIZE;
    else if (keycode == 65364 || keycode == 's') //Tecla para baixo
        next_y += TILE_SIZE;
    else if (keycode == 65307)
    {
        ft_printf("Window closed.\n");
        mlx_destroy_window(game->mlx, game->win);
        exit(EXIT_SUCCESS);
    }

    if (is_valid_move(game, next_x, next_y))
    {
        if (game->map[next_y / TILE_SIZE][next_x / TILE_SIZE] == 'C')
        {
           collect_collectable(game, next_x, next_y);
        }
        else if (game->map[next_y / TILE_SIZE][next_x / TILE_SIZE] == 'E')
        {
            if (!are_collectables_remaining(game))
                handleWindowClose(game);
        }
        game->moves += 1;
        game->x_player = next_x;
        game->y_player = next_y;
    }
    return (0);
}

int key_release(t_game *game)
{
    (void)game;
    return(0);
}
int render_next_frame(t_game *game)
{
    int i = 0;
    int j = 0;
    // Limpa a janela
    mlx_clear_window(game->mlx, game->win);
    usleep(100);
    while(i < MAP_HEIGHT)
    {
        while(j < MAP_WIDTH)
        {
            int x = j * TILE_SIZE;
            int y = i * TILE_SIZE;

            // Exibir imagem correspondente ao elemento do mapa
            if (game->map[i][j] == '1')
            {
                mlx_put_image_to_window(game->mlx, game->win, game->image_wall, x, y);
            } 
            else if (game->map[i][j] == '0')
            {
                mlx_put_image_to_window(game->mlx, game->win, game->image_empty, x, y);
            }
            else if (game->map[i][j] == 'C')
            {
                mlx_put_image_to_window(game->mlx, game->win, game->image_collectible, x, y);
            }
            else if (game->map[i][j] == 'E')
            {
                mlx_put_image_to_window(game->mlx, game->win, game->image_exit, x, y);
            }
            // Adicione mais casos conforme necessário para outros elementos do seu mapa
            j++;
        }
        i++;
        j = 0;
      }
    //update_score_display(game);
   // update_moves_display(game);
    mlx_put_image_to_window(game->mlx, game->win, game->image_player, game->x_player, game->y_player);
    return (0);
}

int main(void)
{
    t_game game;
	int		image_width;
	int		image_height;


    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE, "NoName Game");
    game.exit_confirmation = 0;
    game.color = 0xFF0000;
    game.x_player = 2 * TILE_SIZE;
    game.y_player = 2 * TILE_SIZE;
    game.score = 0;
    game.moves = 0;
    // Inicializar as imagens
    game.image_wall = mlx_xpm_file_to_image(game.mlx, "libraries/mlx/images/wall.xpm", &image_width, &image_height);
    game.image_empty = mlx_xpm_file_to_image(game.mlx, "libraries/mlx/images/empty.xpm", &image_width, &image_height);
    game.image_collectible = mlx_xpm_file_to_image(game.mlx, "libraries/mlx/images/collectible.xpm", &image_width, &image_height);
    game.image_exit = mlx_xpm_file_to_image(game.mlx, "libraries/mlx/images/exit.xpm", &image_width, &image_height);
    game.image_player = mlx_xpm_file_to_image(game.mlx, "libraries/mlx/images/player.xpm", &image_width, &image_height);

    // Verificar se o caminho foi bem-sucedido
    if (game.image_wall == NULL || game.image_empty == NULL || game.image_collectible == NULL || game.image_exit == NULL || game.image_player == NULL)
    {
        fprintf(stderr, "Erro ao carregar uma ou mais imagens.\n");
        // Lide com o erro conforme necessário
        exit(EXIT_FAILURE);
    }

    // Conecta os eventos de tecla e mouse
    mlx_hook(game.win, 2, 1L << 0, key_press, &game);     // Evento para pressionar tecla
    mlx_hook(game.win, 3, 1L << 1, key_release, &game);   // Evento para largar a tecla
    
    mlx_hook(game.win, 33, 1L << 17, handleWindowClose, &game); // Código 33 pode variar, experimente outros valores
    //mlx_loop_hook(game.mlx, check_window_close, &game);    //mlx_hook(game.win, 6, 1L << 6, exit_screen, &game); // movimento do rato
    //mlx_hook(game.win, 4, 1L << 2, exit_screen, &game); // Cliques do rato
    mlx_hook(game.win, 17, 1L << 17, handleWindowClose, &game); // Window close event

    char initial_map[MAP_HEIGHT][MAP_WIDTH] = {
        "1111111111111111111111111",
        "1000000000000000000000001",
        "10000000000CC00000CC00001",
        "1000000000C00000000000C01",
        "1000000000C0000000C000011",
        "1000000000E00000000000001",
        "1000000000000000000000001",
        "1000000000000000000000001",
        "1111111111111111111111111",
    };
    // alocacao do mapa
    game.map = (char**)malloc(MAP_HEIGHT * sizeof(char*));
    int i = 0;
    int j = 0;
    while(i < MAP_HEIGHT)
    {
        game.map[i] = (char*)malloc(MAP_WIDTH * sizeof(char));
        i++;
    }
    // Copie os valores do mapa inicial para a estrutura de jogo
    i = 0;
    while(i < MAP_HEIGHT)
    {
        while(j < MAP_WIDTH)
        {
            game.map[i][j] = initial_map[i][j];
            if (initial_map[i][j] == 'P')
            {
                game.x_player = j * TILE_SIZE; // Defina as coordenadas iniciais do jogador
                game.y_player = i * TILE_SIZE;
            }
            j++;
        }
        j = 0;
        i++;
    }
    
    // Define o loop de renderização
    mlx_loop_hook(game.mlx, render_next_frame, &game);

    // Inicia o loop principal
    mlx_loop(game.mlx);

/* 	for (int i = 0; i < MAP_HEIGHT; i++) {
    free(game.map[i]); }*/

//free(game.map);
    return 0;
}
