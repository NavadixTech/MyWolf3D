/*
** EPITECH PROJECT, 2025
** new_wolf
** File description:
** player_move
*/

#include "my.h"

static void update_position(player_t *p, float dx, float dy, map_t *m)
{
    float new_x = p->pos.x + dx;
    float new_y = p->pos.y + dy;

    if (new_x >= 0 && new_x < m->width && m->grid[(int)new_y][(int)new_x] == 0)
        p->pos.x = new_x;
    if (new_y >= 0 && new_y < m->height && m->grid[(int)new_y][(int)new_x] == 0)
        p->pos.y = new_y;
}

void move_player(player_t *player, map_t *map, sfKeyCode key)
{
    float dx = 0.0f;
    float dy = 0.0f;

    if (key == sfKeyW) {
        dx = cosf(player->angle) * player->speed;
        dy = sinf(player->angle) * player->speed;
    }
    if (key == sfKeyS) {
        dx = -cosf(player->angle) * player->speed;
        dy = -sinf(player->angle) * player->speed;
    }
    if (key == sfKeyA)
        player->angle -= 0.1f;
    if (key == sfKeyD)
        player->angle += 0.1f;
    update_position(player, dx, dy, map);
}