#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "linked_list.h"

struct node {
	Element value;
	struct node *next;
};

struct linked_list_t {
	int size;
	struct node *head;
};

static void print_error(char *message)
{
	printf("%s\n", message);
}

static bool is_valid_index(LinkedList list, int index)
{
	return index >= 0 && index < list->size;
}

static struct node *get_node(LinkedList list, int index)
{
	struct node *current = list->head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	return current;

}

LinkedList ll_create()
{
	LinkedList list = malloc(sizeof(struct linked_list_t));
	if (list == NULL) {
		exit(EXIT_FAILURE);
	}
	list->size = 0;
	list->head = NULL;
	return list;
}

void ll_destroy(LinkedList list)
{
	ll_clear(list);
	free(list);
}

bool ll_add(LinkedList list, int index, Element e)
{
	if (index > list->size) {
		print_error("Cannot add, index is greater than list size.\n");
		return false;
	}

	struct node *new = malloc(sizeof(struct node));
	if (new == NULL) {
		print_error("Failed to add, error creating new node.\n");
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

Element ll_remove(LinkedList list, int index)
{
	if (!is_valid_index(list, index)) {
		print_error("Invalid index for removing.\n");
		return NULL_ELEMENT;
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

Element ll_set(LinkedList list, int index, Element e)
{
	if (!is_valid_index(list, index)) {
		return NULL_ELEMENT;
	}
	struct node *node_at_index = get_node(list, index);
	Element previous_value = node_at_index->value;
	node_at_index->value = e;
	return previous_value;
}

Element ll_get(LinkedList list, int index)
{
	if (!is_valid_index(list, index)) {
		return NULL_ELEMENT;
	}
	return get_node(list, index)->value;
}	

int ll_index_of(LinkedList list, Element e)
{
	struct node *current = list->head;
	for (int i = 0; i < list->size; i++) {
		if (current-> value == e) {
			return i;
		}
		current = current->next;
	}
	return -1;
}

int ll_size(LinkedList list)
{
	return list->size;
}

bool ll_is_empty(LinkedList list)
{
	return list->head == NULL;
}

void ll_clear(LinkedList list)
{
	while (list->head != NULL) {
		list->head->value = NULL_ELEMENT;
		list->head = list->head->next;
		list->size--;
	}
}

void ll_print(LinkedList list)
{
	if (ll_is_empty(list)) {
		printf("(Empty list)\n");
		return;
	}
	struct node *current = list->head;
	printf("(");
	for(int i = 0; i < list->size-1; i++) {
		printf("%d, ", current->value);
		current = current->next;
	}
	printf("%d)\n", current->value);
}
