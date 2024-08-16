#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "linked_list.h"

struct node {
	Element value;
	node *next;
};

struct linked_list_t {
	int size;
	node *head;
};

static void print_error(char *message)
{
	printf("%s\n", message);
}

LinkedList create()
{
	LinkedList list = malloc(sizeof(struct linked_list_t));
	if (list == NULL) {
		exit(EXIT_FAILURE);
	}
	list->size = 0;
	list->head = NULL;
}

void destroy(ArrayList list)
{
	clear(list);
	free(list);
}

bool add_to_list(ArrayList list, int index, Element e)
{
	struct node *new = malloc(sizeof(struct node));
	if (new == NULL) {
		return false;
	}
	new->value = e;

	// Adding to beginning
	if (index == 0) {
		new->next = list->head;
		list->head = new;
		return true;
	}

	// Adding to end
	if (index == list->size) {
		node *current = list->head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = new;
		new->next = NULL;
		return true;
	}

	// Adding to middle
	int i = 0;
	node *current = list->head;
	node *previous = NULL;
	while (i < index && current->next != NULL) {
		previous = current;
		current = current->next;
		i++;
	}
	previous->next = new;
	new->next = current;
	return true;
}

Element remove_from_list(ArrayList list, int index)
{
	
}

Element set(ArrayList list, int index, Element e)
{
	
}

Element get(ArrayList list, int index)
{
	
}

int get_index(ArrayList list, Element e)
{
	
}

int size(ArrayList list)
{
	return list->size;
}

bool is_empty(ArrayList list)
{
	return list->head == NULL;
}

void clear(ArrayList list)
{
	
}

void print_list(ArrayList list)
{
	
}
