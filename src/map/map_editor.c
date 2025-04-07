/*
** EPITECH PROJECT, 2025
** MyWolf3D
** File description:
** map_editor
*/

#include "my.h"

void edit_map(map_t *map, sfVector2i pos, int value)
{
    int grid_x = pos.x / GRID_SIZE;
    int grid_y = pos.y / GRID_SIZE;

    if (grid_x >= 0 && grid_x < map->width && grid_y >= 0 && grid_y < map->height) {
        map->grid[grid_y][grid_x] = value; // 1 pour mur, 0 pour vide
    }
}

void render_grid(game_t *game)
{
    sfRectangleShape *cell = sfRectangleShape_create();
    sfVector2f size = {GRID_SIZE, GRID_SIZE};
    int x, y;

    sfRectangleShape_setSize(cell, size);
    sfRectangleShape_setFillColor(cell, sfTransparent);
    sfRectangleShape_setOutlineColor(cell, sfColor_fromRGB(255, 255, 255));
    sfRectangleShape_setOutlineThickness(cell, 1);
    for (y = 0; y < game->map->height; y++) {
        for (x = 0; x < game->map->width; x++) {
            sfRectangleShape_setPosition(cell, (sfVector2f){x * GRID_SIZE, y * GRID_SIZE});
            if (game->map->grid[y][x] == 1)
                sfRectangleShape_setFillColor(cell, sfColor_fromRGB(100, 100, 100));
            else
                sfRectangleShape_setFillColor(cell, sfTransparent);
            sfRenderWindow_drawRectangleShape(game->window, cell, NULL);
        }
    }
    sfRectangleShape_destroy(cell);
}