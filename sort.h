#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/* print_array */
void print_array(const int *array, size_t siz);

/* print_list */
void print_list(const listint_t *list);

/* Doubly linked list */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

#endif