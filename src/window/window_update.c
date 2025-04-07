/*
** EPITECH PROJECT, 2025
** new_wolf
** File description:
** window_update
*/

#include "my.h"

static void handle_movement(game_t *game, sfEvent *event)
{
    if (event->key.code == sfKeyW)
        move_player(game->player, game->map, sfKeyW);
    if (event->key.code == sfKeyS)
        move_player(game->player, game->map, sfKeyS);
    if (event->key.code == sfKeyA)
        move_player(game->player, game->map, sfKeyA);
    if (event->key.code == sfKeyD)
        move_player(game->player, game->map, sfKeyD);
}

void update_window(game_t *game)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (event.type == sfEvtKeyPressed)
            handle_movement(game, &event);
    }
}