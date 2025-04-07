/*
** EPITECH PROJECT, 2025
** new_wolf
** File description:
** main
*/

#include "my.h"
#include <stdio.h>

int main(void)
{
    game_t *game = init_game();
    if (!game) {
        fprintf(stderr, "Error: Failed to initialize game\n");
        return 84;
    }

    while (sfRenderWindow_isOpen(game->window)) {
        update_window(game);
        render_floor_ceiling(game);
        render_walls(game);
        sfRenderWindow_display(game->window);
    }
    free_all(&game->mem_list);
    sfRenderWindow_destroy(game->window);
    return 0;
}