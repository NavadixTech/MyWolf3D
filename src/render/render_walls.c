/*
** EPITECH PROJECT, 2025
** MyWolf3D
** File description:
** render_walls
*/

#include "my.h"
#include <math.h>

static float cast_ray(player_t *p, map_t *m, float angle)
{
    float ray_x = p->pos.x;
    float ray_y = p->pos.y;
    float dx = cosf(angle);
    float dy = sinf(angle);

    while (ray_x >= 0 && ray_x < m->width && ray_y >= 0 && ray_y < m->height) {
        if (m->grid[(int)ray_y][(int)ray_x] == 1)
            return sqrtf(powf(ray_x - p->pos.x, 2) + powf(ray_y - p->pos.y, 2));
        ray_x += dx * 0.1f;
        ray_y += dy * 0.1f;
    }
    return 100.0f;
}

static void draw_wall_slice(game_t *game, int x, float height)
{
    sfRectangleShape *slice = sfRectangleShape_create();
    sfVector2f size = {1, height};
    sfVector2f pos = {x, 300 - height / 2};
    sfVector2u tex_size;

    sfRectangleShape_setSize(slice, size);
    sfRectangleShape_setPosition(slice, pos);
    if (game->map->wall_tex) {
        tex_size = sfTexture_getSize(game->map->wall_tex);
        sfRectangleShape_setTexture(slice, game->map->wall_tex, sfTrue);
        sfRectangleShape_setTextureRect(slice, (sfIntRect){x % tex_size.x, 0, 1, tex_size.y});
    } else {
        sfRectangleShape_setFillColor(slice, sfColor_fromRGB(150, 150, 150));
    }
    sfRenderWindow_drawRectangleShape(game->window, slice, NULL);
    sfRectangleShape_destroy(slice);
}

void render_walls(game_t *game)
{
    float fov = 1.0f;
    float angle;
    float distance;
    int x;

    for (x = 0; x < 800; x++) {
        angle = game->player->angle + (x - 400) * (fov / 800);
        distance = cast_ray(game->player, game->map, angle);
        draw_wall_slice(game, x, 600.0f / (distance + 0.1f));
    }
}