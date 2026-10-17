#ifndef LIBADT_H
#define LIBADT_H

#include <stddef.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;


typedef struct LinkedList {
    Node *head;
    Node *tail;
    size_t size;
} LinkedList;

/* Initialize a list before using any of its operations. */

/**
 * Initialize a list
 */
void linkedlist_init(LinkedList *list);

/**
 * Add a value at either end of the list
 * Return 1 on success, 0 on failure
 */
int addfront(LinkedList *list, int value);
int addend(LinkedList *list, int value);

/**
 * Remove from either end.
 * If *value is defined, store the removed value there.
 * Return 1 if item successfully removed, or 0 on failure
 */
int removefront(LinkedList *list, int *value);
int removeend(LinkedList *list, int *value);

/**
 * Remove the index.
 * Return 1 if item successfully removed, or 0 on failure
 */
int removeindex(LinkedList *list, size_t index, int *value);

#endif
