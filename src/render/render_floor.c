/*
** EPITECH PROJECT, 2025
** MyWolf3D
** File description:
** render_floor
*/

#include "my.h"

static void set_texture_offset(sfSprite *sprite, sfTexture *tex, player_t *player)
{
    sfVector2u tex_size = sfTexture_getSize(tex);
    sfIntRect rect;
    float speed_factor = 0.5f; // Réduit la vitesse de défilement
    float forward_offset = -player->pos.y * tex_size.y * speed_factor;
    float side_offset = player->pos.x * tex_size.x * speed_factor * 0.2f;

    rect.left = (int)side_offset % tex_size.x;
    rect.top = (int)forward_offset % tex_size.y;
    rect.width = 800;
    rect.height = 300;
    sfSprite_setTextureRect(sprite, rect);
}

static void render_surface(game_t *game, sfTexture *tex, float y_pos)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {0, y_pos};
    sfVector2f scale;

    if (tex) {
        sfTexture_setRepeated(tex, sfTrue);
        sfSprite_setTexture(sprite, tex, sfTrue);
        scale.x = 800.0f / sfTexture_getSize(tex).x;
        scale.y = 300.0f / sfTexture_getSize(tex).y;
        sfSprite_setScale(sprite, scale);
        set_texture_offset(sprite, tex, game->player);
    } else {
        sfRectangleShape *rect = sfRectangleShape_create();
        sfRectangleShape_setSize(rect, (sfVector2f){800, 300});
        sfRectangleShape_setPosition(rect, pos);
        sfRectangleShape_setFillColor(rect, sfColor_fromRGB(y_pos == 0 ? 50 : 100, 50, 50));
        sfRenderWindow_drawRectangleShape(game->window, rect, NULL);
        sfRectangleShape_destroy(rect);
        sfSprite_destroy(sprite);
        return;
    }
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(game->window, sprite, NULL);
    sfSprite_destroy(sprite);
}

void render_floor_ceiling(game_t *game)
{
    render_surface(game, game->map->ceiling_tex, 0.0f);
    render_surface(game, game->map->floor_tex, 300.0f);
}