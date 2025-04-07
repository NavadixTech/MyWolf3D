/*
** EPITECH PROJECT, 2025
** new_wolf
** File description:
** window_init
*/

#include "my.h"
#include <stdio.h>

static sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *win;

    win = sfRenderWindow_create(mode, "Wolf3D", sfClose, NULL);
    if (!win)
        fprintf(stderr, "Error: Failed to create window\n");
    sfRenderWindow_setFramerateLimit(win, 60);
    return win;
}

game_t *init_game(void)
{
    game_t *game = my_alloc(sizeof(game_t), NULL);
    if (!game) {
        fprintf(stderr, "Error: Game allocation failed\n");
        return NULL;
    }
    game->mem_list = NULL;
    game->window = create_window();
    game->player = init_player();
    game->map = init_map(16, 16);
    if (!game->window || !game->player || !game->map) {
        fprintf(stderr, "Error: Subcomponent initialization failed\n");
        free_all(&game->mem_list);
        return NULL;
    }
    game->editor_mode = false;
    return game;
}