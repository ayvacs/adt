#ifndef LIBADT_H
#define LIBADT_H

#include <stddef.h>

typedef struct List List;

/**
 * Create an empty list.
 * Return a pointer to the list, or NULL on failure.
 */
List *list_create(void);

/**
 * Free the list and all of its items.
 */
void list_destroy(List *list);

/**
 * Add a value at the front or end of the list.
 * Return 1 on success, or 0 on failure.
 */
int list_add_front(List *list, int value);
int list_add_end(List *list, int value);

/**
 * Remove a value from the front, end, or zero-based index.
 * If value is not NULL, store the removed value there.
 * Return 1 if an item was removed, or 0 if the list is empty,
 * the index is out of range, or the list is NULL.
 */
int list_remove_front(List *list, int *value);
int list_remove_end(List *list, int *value);
int list_remove_index(List *list, size_t index, int *value);

/**
 * Return the number of items in the list.
 */
size_t list_size(const List *list);

#endif
