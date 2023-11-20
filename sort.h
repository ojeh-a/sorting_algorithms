#ifndef SORT_H
#define SORT_H


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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

/* print_array */
void print_array(const int *array, size_t siz);
void swap_ints(int *a, int *b);
void cocktail_sort_list(listint_t **list);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);


/* print_list */
void print_list(const listint_t *list);
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2);

/* ALGORITHMS */

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);

#endif
