/*
** EPITECH PROJECT, 2025
** new_wolf
** File description:
** player_init
*/

#include "my.h"

player_t *init_player(void)
{
    player_t *player = my_alloc(sizeof(player_t), NULL);

    if (!player)
        return NULL;
    player->pos.x = 2.0f;
    player->pos.y = 2.0f;
    player->angle = 0.0f;
    player->speed = 0.1f;
    return player;
}