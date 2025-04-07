/*
** EPITECH PROJECT, 2025
** new_wolf
** File description:
** map_init
*/

#include "my.h"
#include <stdio.h>

static int **create_grid(int w, int h, memory_t **list)
{
    int **grid = my_alloc(sizeof(int *) * h, list);

    if (!grid)
        return NULL;
    for (int i = 0; i < h; i++) {
        grid[i] = my_alloc(sizeof(int) * w, list);
        if (!grid[i])
            return NULL;
        for (int j = 0; j < w; j++)
            grid[i][j] = (i == 0 || i == h-1 || j == 0 || j == w-1) ? 1 : 0;
    }
    return grid;
}

map_t *init_map(int width, int height)
{
    map_t *map = my_alloc(sizeof(map_t), NULL);

    if (!map)
        return NULL;
    map->width = width;
    map->height = height;
    map->mem_list = NULL;
    map->grid = create_grid(width, height, &map->mem_list);
    map->wall_tex = sfTexture_createFromFile("wall.png", NULL);
    if (!map->grid) {
        fprintf(stderr, "Error: Map grid allocation failed\n");
        free_all(&map->mem_list);
        return NULL;
    }
    if (!map->wall_tex)
        fprintf(stderr, "Warning: Failed to load wall.png, using default color\n");
    return map;
}