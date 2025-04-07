/*
** EPITECH PROJECT, 2025
** new_wolf
** File description:
** render_floor
*/

#include "my.h"

void render_floor_ceiling(game_t *game)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f size = {800, 300};

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, sfColor_fromRGB(50, 50, 50));
    sfRectangleShape_setPosition(rect, (sfVector2f){0, 0});
    sfRenderWindow_drawRectangleShape(game->window, rect, NULL);
    sfRectangleShape_setPosition(rect, (sfVector2f){0, 300});
    sfRectangleShape_setFillColor(rect, sfColor_fromRGB(100, 100, 100));
    sfRenderWindow_drawRectangleShape(game->window, rect, NULL);
    sfRectangleShape_destroy(rect);
}