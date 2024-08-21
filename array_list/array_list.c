#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "array_list.h"

struct array_list_t {
	int capacity;
	int size;
	Element *array;
};

static void print_error(char *message)
{
	printf("%s\n", message);
}

static bool is_full(ArrayList list)
{
	return list->size == list->capacity;
}

static bool is_valid_index(ArrayList list, int index)
{
	return index >= 0 && index < list->size;
}

static bool al_expand(ArrayList list)
{
	Element* temp = realloc(list->array, sizeof(Element) * list->capacity * 2);
	if (temp == NULL) {
		print_error("Error: failed to expand array.\n");
		return;
	}
	list->array = temp;
	list->capacity *= 2;
}

ArrayList al_create(int initial_capacity)
{
	ArrayList list = malloc(sizeof(struct array_list_t));
	if (list == NULL) {
		print_error("Error: failed creating ArrayList.\n");
		return NULL;
	}
	list->capacity = initial_capacity;
	list->size = 0;
	list->array = malloc(sizeof(Element) * initial_capacity);
	if (list->array == NULL) {
		print_error("Error: failed creating array.\n");
		return NULL;
	}
	return list;
}

void al_destroy(ArrayList list)
{
	free(list->array);
	free(list);
}

bool al_add(ArrayList list, int index, Element e)
{
	if (is_full(list)) {
		if (!al_expand(list)) {
			return false;
		}
	}
	if (!(is_valid_index(list, index) || index ==list->size)) {
		print_error("Error: cannot add, invalid index.");
		return false;
	}
	for (int i = list->size; i > index; i--) {
		list->array[i] = list->array[i-1];
	}
	list->array[index] = e;
	list->size++;
	return true;
}

Element al_remove(ArrayList list, int index)
{
	if (al_is_empty(list)) {
		print_error("Error: cannot remove from empty list.");
		return NULL_ELEMENT;
	}
	if (!is_valid_index(list, index)) {
		print_error("Error: cannot remove, invalid index.");
		return NULL_ELEMENT;
	}
	Element e = list->array[index];
	for (int i = index+1; i < list->size; i++) {
		list->array[i-1] = list->array[i];
	}
	list->size--;
	return e;
}

Element al_set(ArrayList list, int index, Element e)
{
	if (al_is_empty(list)) {
		print_error("Error: cannot set, list is empty.");
		return NULL_ELEMENT;
	}
	if (!(is_valid_index(list, index))) {
		print_error("Error: cannot set, invalid index.");
		return NULL_ELEMENT;
	}
	Element previous = list->array[index];
	list->array[index] = e;
	return previous;
}

Element al_get(ArrayList list, int index)
{
	if (al_is_empty(list)) {
		print_error("Error: cannot get, list is empty.");
		return NULL_ELEMENT;
	}
	if (!is_valid_index(list, index)) {
		print_error("Error: cannot get, invalid index.");
		return NULL_ELEMENT;
	}
	return list->array[index];
}

int al_index_of(ArrayList list, Element e)
{
	for (int i = 0; i < list->size; i++) {
		if (list->array[i] == e) {
			return i;
		}
	}
	return -1;
}

int al_size(ArrayList list)
{
	return list->size;
}

bool al_is_empty(ArrayList list)
{
	return list->size == 0;
}

void al_clear(ArrayList list)
{
	for (int i = 0; i < list->size; i++) {
		list->array[i] = 0;
	}
	list->size = 0;
}

void al_print(ArrayList list)
{
	if (al_is_empty(list)) {
		printf("List is empty.\n");
	} else {
		for (int i = 0; i < list->size-1; i++) {
			printf("%d, ", list->array[i]);
		}
		printf("%d\n", list->array[list->size-1]);
	}
	printf("Size: %d\n", list->size);
	printf("Capacity: %d\n", list->capacity);
}

