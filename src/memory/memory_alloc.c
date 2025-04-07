/*
** EPITECH PROJECT, 2025
** new_wolf
** File description:
** memory_alloc
*/

#include "my.h"

void *my_alloc(size_t size, memory_t **list)
{
    void *ptr = malloc(size);
    memory_t *node;

    if (!ptr)
        return NULL;
    node = malloc(sizeof(memory_t));
    if (!node) {
        free(ptr);
        return NULL;
    }
    node->ptr = ptr;
    node->next = (list ? *list : NULL);
    if (list)
        *list = node;
    return ptr;
}