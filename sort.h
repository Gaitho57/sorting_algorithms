#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdbool.h>

/* Function prototypes for the sorting algorithms */

/* Bubble Sort */
void bubble_sort(int *array, size_t size);

/* Insertion Sort */
typedef struct listint_s
{
    int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void insertion_sort_list(listint_t **list);
void print_list(const listint_t *list);

/* Selection Sort */
void selection_sort(int *array, size_t size);

/* Quick Sort */
void quick_sort(int *array, size_t size);
void print_array(const int *array, size_t size);

#endif /* SORT_H */

