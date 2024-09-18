
#include <stdbool.h>
#include <stdlib.h>
#include "array_list.h"

struct array_list_t {
	size_t capacity;
	size_t size;
	Element *array;
};

static bool al_is_full(ArrayList list) 
{
	return list->size == list->capacity;
}

static bool al_is_valid_index(ArrayList list, size_t index)
{
	return index < list->size;
}

static bool al_expand(ArrayList list)
{
	Element* temp = realloc(list->array, sizeof(Element) * list->capacity * 2);
	if (temp == NULL) {
		return false;
	}
	list->array = temp;
	list->capacity *= 2;
	return true;
}

ArrayList al_create(size_t initial_capacity)
{
	ArrayList list = calloc(1, sizeof(struct array_list_t));
	if (list == NULL) {
		return NULL;
	}
	list->capacity = initial_capacity;
	list->size = 0;
	list->array = malloc(sizeof(Element) * initial_capacity);
	if (list->array == NULL) {
		free(list);
		return NULL;
	}
	return list;
}


void al_destroy(ArrayList list)
{
	free(list->array);
	free(list);
}


bool al_add(ArrayList list, size_t index, Element e)
{
	if (al_is_full(list)) {
		if (!al_expand(list)) {
			return false;
		}
	}
	if (!(al_is_valid_index(list, index) || index ==list->size)) {
		return false;
	}
	for (size_t i = list->size; i > index; i--) {
		list->array[i] = list->array[i-1];
	}
	list->array[index] = e;
	list->size++;
	return true;
}


Element al_remove(ArrayList list, size_t index)
{
	if (al_is_empty(list)) {
		return NULL;
	}
	if (!al_is_valid_index(list, index)) {
		return NULL;
	}
	Element e = list->array[index];
	for (size_t i = index+1; i < list->size; i++) {
		list->array[i-1] = list->array[i];
	}
	list->size--;
	return e;
}


Element al_set(ArrayList list, size_t index, Element e)
{
	if (al_is_empty(list)) {
		return NULL;
	}
	if (!al_is_valid_index(list, index)) {
		return NULL;
	}
	Element previous = list->array[index];
	list->array[index] = e;
	return previous;
}


Element al_get(ArrayList list, size_t index)
{
	if (al_is_empty(list)) {
		return NULL;
	}
	if (!al_is_valid_index(list, index)) {
		return NULL;
	}
	return list->array[index];
}


int al_index_of(ArrayList list, Element e, CompareFunc compare)
{
	for (int i = 0; i < list->size; i++) {
		if (compare(list->array[i], e) == 0) {
			return i;
		}
	}
	return -1;
}


size_t al_size(ArrayList list)
{
	return list->size;
}


bool al_is_empty(ArrayList list)
{
	return list->size == 0;
}


void al_clear(ArrayList list)
{
	for (size_t i = 0; i < list->size; i++) {
		list->array[i] = NULL;
	}
	list->size = 0;
}


void al_sort(ArrayList list, CompareFunc compare)
{
	for (int i = 1; i < list->size; i++) {
		Element key = list->array[i];
		int j = i - 1;
		while (j >= 0 && compare(list->array[j], key) > 0) {
			list->array[j+1] = list->array[j];
			j--;
		}
		list->array[j+1] = key;
	}
}









