/*
** EPITECH PROJECT, 2025
** MyWolf3D
** File description:
** map_textures
*/

#include "my.h"
#include <stdio.h>

int load_textures(map_t *map)
{
    int success = 1;

    map->wall_tex = sfTexture_createFromFile("wall.png", NULL);
    map->floor_tex = sfTexture_createFromFile("floor.png", NULL);
    map->ceiling_tex = sfTexture_createFromFile("ceiling.png", NULL);

    if (!map->wall_tex) {
        fprintf(stderr, "Error: Failed to load wall.png\n");
        success = 0;
    }
    if (!map->floor_tex) {
        fprintf(stderr, "Error: Failed to load floor.png\n");
        success = 0;
    }
    if (!map->ceiling_tex) {
        fprintf(stderr, "Error: Failed to load ceiling.png\n");
        success = 0;
    }
    return success;
}