/*
** EPITECH PROJECT, 2025
** MyWolf3D
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <math.h>

    #define GRID_SIZE 32

typedef struct s_memory {
    void *ptr;
    struct s_memory *next;
} memory_t;

typedef struct s_player {
    sfVector2f pos;
    float angle;
    float speed;
} player_t;

typedef struct s_map {
    int **grid;
    int width;
    int height;
    sfTexture *wall_tex;
    sfTexture *floor_tex;
    sfTexture *ceiling_tex;
    memory_t *mem_list;
} map_t;

typedef struct s_game {
    sfRenderWindow *window;
    player_t *player;
    map_t *map;
    memory_t *mem_list;
    bool editor_mode;
} game_t;

// Prototypes
game_t *init_game(void);
void update_window(game_t *game);
player_t *init_player(void);
void move_player(player_t *player, map_t *map, sfKeyCode key);
map_t *init_map(int width, int height);
void render_map(game_t *game);
void edit_map(map_t *map, sfVector2i pos, int value);
void *my_alloc(size_t size, memory_t **list);
void free_all(memory_t **list);
void render_walls(game_t *game);
void render_floor_ceiling(game_t *game);
void render_grid(game_t *game);
#endif