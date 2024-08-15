#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "array_list.h"

struct array_list_t {
	int capacity;
	int size;
	Element *array;
};

static bool is_full(ArrayList list)
{
	return list->size == list->capacity;
}

static void expand(ArrayList list)
{
	Element* temp = realloc(list->array, sizeof(Element) * list->capacity * 2);
	if (temp == NULL) {
		return;
	}
	list->array = temp;
	list->capacity *= 2;
}

static void print_error(char *message)
{
	printf("%s\n", message);
}

ArrayList create(int initial_capacity)
{
	ArrayList list = malloc(sizeof(struct array_list_t));
	if (list == NULL) {
		exit(EXIT_FAILURE);
	}
	list->capacity = initial_capacity;
	list->size = 0;
	list->array = malloc(sizeof(Element) * initial_capacity);
	if (list->array == NULL) {
		exit(EXIT_FAILURE);
	}
	return list;
}

void destroy(ArrayList list)
{
	free(list->array);
	free(list);
}

bool add_to_list(ArrayList list, int index, Element e)
{
	if (is_full(list)) {
		expand(list);
	}
	if (index > list->size || index < 0) {
		print_error("Cannot add, invalid index.");
		return false;
	}
	for (int i = list->size; i > index; i--) {
		list->array[i] = list->array[i-1];
	}
	list->array[index] = e;
	list->size++;
	return true;
}

Element remove_from_list(ArrayList list, int index)
{
	if (is_empty(list)) {
		print_error("Cannot remove from empty list.");
		return -1;
	}
	if (index > list->size-1 || index < 0) {
		print_error("Cannot remove, invalid index.");
		return -1;
	}
	Element e = list->array[index];
	for (int i = index+1; i < list->size; i++) {
		list->array[i-1] = list->array[i];
	}
	list->size--;
	return e;
}

Element set(ArrayList list, int index, Element e)
{
	if (is_empty(list)) {
		print_error("Cannot set, list is empty.");
		return -1;
	}
	if (index > list->size-1 || index < 0) {
		print_error("Cannot set, invalid index.");
		return -1;
	}
	Element previous = list->array[index];
	list->array[index] = e;
	return previous;
}

Element get(ArrayList list, int index)
{
	if (is_empty(list)) {
		print_error("Cannot get, list is empty.");
		return -1;
	}
	if (index > list->size-1 || index < 0) {
		print_error("Cannot get, invalid index.");
		return -1;
	}
	return list->array[index];
}

int get_index(ArrayList list, Element e)
{
	for (int i = 0; i < list->size; i++) {
		if (list->array[i] == e) {
			return i;
		}
	}
	return -1;
}

int size(ArrayList list)
{
	return list->size;
}

bool is_empty(ArrayList list)
{
	return list->size == 0;
}

void clear(ArrayList list)
{
	for (int i = 0; i < list->size; i++) {
		list->array[i] = 0;
	}
	list->size = 0;
}

void print_list(ArrayList list)
{
	if (is_empty(list)) {
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

