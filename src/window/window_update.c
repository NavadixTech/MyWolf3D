/*
** EPITECH PROJECT, 2025
** MyWolf3D
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
    if (event->key.code == sfKeyE)
        game->editor_mode = !game->editor_mode;
}

void update_window(game_t *game)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (event.type == sfEvtKeyPressed)
            handle_movement(game, &event);
        if (game->editor_mode && event.type == sfEvtMouseButtonPressed)
            edit_map(game->map, sfMouse_getPositionRenderWindow(game->window), 1);
    }
}