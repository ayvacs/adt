#include "libadt.h"

#include <stdlib.h>

void linkedlist_init(LinkedList *list) {
    if (list == NULL)
        return;

    // empty list: no endpoints, size of zero
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int addfront(LinkedList *list, int value) {
    if (list == NULL)
        return 0;

    Node *node = malloc(sizeof(*node));
    if (node == NULL)
        return 0;

    node->data = value;
    node->next = list->head;

    // the new node is the tail as well as the head
    list->head = node;
    if (list->tail == NULL)
        list->tail = node;

    list->size++;
    return 1;
}

int addend(LinkedList *list, int value) {
    if (list == NULL)
        return 0;

    Node *node = malloc(sizeof(*node));
    if (node == NULL)
        return 0;

    node->data = value;
    node->next = NULL;
    
    // link after the existing tail, or set as the head for an empty list
    if (list->tail == NULL)
        list->head = node;
    else
        list->tail->next = node;

    list->tail = node;
    list->size++;
    return 1;
}

int removefront(LinkedList *list, int *value) {
    if (list == NULL || list->head == NULL)
        return 0;

    Node *node = list->head;
    if (value != NULL)
        *value = node->data;
    
    // removing the head leaves both endpoints empty
    list->head = node->next;
    if (list->head == NULL)
        list->tail = NULL;

    list->size--;
    free(node);
    return 1;
}

int removeend(LinkedList *list, int *value) {
    if (list == NULL || list->tail == NULL)
        return 0;

    Node *node = list->tail;
    if (value != NULL)
        *value = node->data;

    // case 1: one-item list
    if (list->head == node) {
        list->head = NULL;
        list->tail = NULL;
    
    // case 2: more than one-item list
    } else {
        Node *previous = list->head;
        while (previous->next != node)
            previous = previous->next;
        previous->next = NULL;
        list->tail = previous;
    }

    list->size--;
    free(node);
    return 1;
}

int removeindex(LinkedList *list, size_t index, int *value) {
    if (list == NULL || index >= list->size)
        return 0;
    if (index == 0)
        return removefront(list, value);

    // stop at the node before the one being removed
    Node *previous = list->head;
    for (size_t i = 1; i < index; i++)
        previous = previous->next;

    Node *node = previous->next;
    if (value != NULL)
        *value = node->data;
    previous->next = node->next;
    if (node == list->tail)
        list->tail = previous;
    list->size--;
    free(node);
    return 1;
}
