#include <stdbool.h>
#include <stdlib.h>
#include "singly_linked_list.h"

struct node {
    Element value;
    struct node *next;
};

struct singly_linked_list_t {
    size_t size;
    struct node *head;
};

static bool sll_is_valid_index(SinglyLinkedList list, size_t index)
{
    return index < list->size;
}

static struct node *get_node(SinglyLinkedList list, size_t index)
{
    struct node *current = list->head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}

SinglyLinkedList sll_create()
{
    SinglyLinkedList list = malloc(sizeof(struct singly_linked_list_t));
    if (list != NULL) {
        list->size = 0;
        list->head = NULL;
    }
    return list;
}

void sll_destroy(SinglyLinkedList list)
{
    sll_clear(list);
    free(list);
}

bool sll_add(SinglyLinkedList list, size_t index, Element e)
{
    if (index > list->size) {
        return false;
    }

    struct node *new = malloc(sizeof(struct node));
    if (new == NULL) {
        return false;
    }
    new->value = e;

    if (index == 0) {
        new->next = list->head;
        list->head = new;
    } else {
        struct node *before = get_node(list, index-1);
        new->next = before->next;
        before->next = new;
    }

    list->size++;
    return true;
}

Element sll_remove(SinglyLinkedList list, size_t index)
{
    if (!sll_is_valid_index(list, index)) {
        return NULL;
    }
    struct node *removed = NULL;
    if (index == 0) {
        removed = list->head;
        list->head = list->head->next;
    } else {
        struct node *before = get_node(list, index-1);
        removed = before->next;
        before->next = removed->next;
    }
    list->size--;
    return removed->value;
}

Element sll_set(SinglyLinkedList list, size_t index, Element e)
{
    if (!sll_is_valid_index(list, index)) {
        return NULL;
    }
    struct node *node_at_index = get_node(list, index);
    Element previous_value = node_at_index->value;
    node_at_index->value = e;
    return previous_value;
}

Element sll_get(SinglyLinkedList list, size_t index)
{
    if (!sll_is_valid_index(list, index)) {
        return NULL;
    }
    return get_node(list, index)->value;
}

int sll_index_of(SinglyLinkedList list, Element e, CompareFunc compare)
{
    struct node *current = list->head;
    for (int i = 0; i < list->size; i++) {
        if (compare(current-> value, e) == 0) {
            return i;
        }
        current = current->next;
    }
    return -1;
}

size_t sll_size(SinglyLinkedList list)
{
    return list->size;
}

bool sll_is_empty(SinglyLinkedList list)
{
    return list->head == NULL;
}

void sll_clear(SinglyLinkedList list)
{
    while (list->head != NULL) {
        struct node *temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
    }
}

void sll_sort(SinglyLinkedList list, CompareFunc compare) {
    if (list->head == NULL || list->head->next == NULL) {
        return;
    }
    struct node *sorted = NULL;
    struct node *current = list->head;

    while (current != NULL) {
        struct node *next = current->next;

        if (sorted == NULL || compare(sorted->value, current->value) > 0) {
            current->next = sorted;
            sorted = current;
        } else {
            struct node *temp = sorted;
            while (temp->next != NULL && compare(temp->next->value, current->value) < 0) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    list->head = sorted;
}





