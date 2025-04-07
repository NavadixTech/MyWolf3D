/*
** EPITECH PROJECT, 2025
** new_wolf
** File description:
** memory_free
*/

#include "my.h"

void free_all(memory_t **list)
{
    memory_t *current = *list;
    memory_t *next;

    while (current) {
        next = current->next;
        free(current->ptr);
        free(current);
        current = next;
    }
    *list = NULL;
}