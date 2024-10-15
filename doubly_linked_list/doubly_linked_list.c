#include <stdbool.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

struct node {
    Element value;
    struct node *next;
    struct node *prev;
};

struct doubly_linked_list_t {
    size_t size;
    struct node *head;
    struct node *tail;
};

static bool is_valid_index(DoublyLinkedList list, size_t index)
{
    return index < list->size;
}

static struct node *get_node(DoublyLinkedList list, size_t index)
{
    if (index < list->size / 2) {
    	struct node *current = list->head;
    	for (size_t i = 0; i < index; i++) {
        	current = current->next;
    	}
    	return current;
    } else {
    	struct node *current = list->tail;
    	for (size_t i = (list->size - 1); i >= index) {
    		current = current->prev;
    	}
    	return current;
	}
}

DoublyLinkedList dll_create(size_t initial_capacity)
{
	DoublyLinkedList list = malloc(sizeof(struct doubly_linked_list_t));
	if (list != NULL) {
        list->size = 0;
        list->head = NULL;
        list->tail = NULL;
    }
    return list;
}

void dll_destroy(DoublyLinkedList list)
{
	sll_clear(list);
    free(list);
}

bool dll_add(DoublyLinkedList list, size_t index, Element e)
{
	if (index > list->size) {
        return false;
    }

    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        return false;
    }
    new_node->value = e;

    if (index == 0) {
    	new_node->prev = NULL;
    	new_node->next = list->head;
    	list->head->prev = new_node;
    } else if (index == list->size) {
    	new_node->prev = list->tail;
    	new_node->next = NULL;
    	list->tail->next = new_node;
    } else {
    	struct node* before = get_node(list, index-1);
   		new_node->prev = before;
    	new_node->next = before->next;
    	before->next = new_node;
	}
	list->size++;
	return true;
}

Element dll_remove(DoublyLinkedList list, size_t index)
{
	if (!is_valid_index(list, index)) {
        return NULL;
    }
    if (index == 0) {
    	struct node* removed = list->head;
    	list->head = list->head->next;
    	list->head->prev = NULL;
    } else if (index == list->size-1) {
    	struct node* removed = list->tail;
    	list->tail = list->tail->prev;
    	list->tail->next = NULL;
    } else {
    	struct node* removed = get_node(list, index);
    	removed->prev->next = removed->next;
    	removed->next->prev = removed->prev;
    }
    list->size--;
    return removed->value;
}

Element dll_set(DoublyLinkedList list, size_t index, Element e);

Element dll_get(DoublyLinkedList list, size_t index);

int dll_index_of(DoublyLinkedList list, Element e, CompareFunc compare);

size_t dll_size(DoublyLinkedList list)
{
	return list->size;
}

bool dll_is_empty(DoublyLinkedList list)
{
	return list->size == 0;
}

void dll_clear(DoublyLinkedList list);

void dll_sort(DoublyLinkedList list, CompareFunc compare);

#endif // DOUBLY_LINKED_LIST_H