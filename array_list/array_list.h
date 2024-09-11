#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdbool.h>
#include <stddef.h>

/* A dynamically expanding, array based implentation of an ordered list. */ 

/* Requires two client-defined functions: */
/* compare: takes two void pointers, and returns an int
   returns < 0 if the first element is less than the second
   returns > 0 if the first element is greater than the second
   returns 0 if the elements are equal */
/* print_item: takes one void pointer, and prints the value of an element */

#define Element void *
#define NULL_ELEMENT 0

typedef struct array_list_t *ArrayList;

/**********************************************************
 * Creates a new array list. Takes two function pointers, a comparison function and a printing function.
 **********************************************************/
ArrayList al_create(size_t initial_capacity, int (*compare)(Element, Element), void (*print_item)(Element));

/**********************************************************
 * Destroys the given array list.
 **********************************************************/
void al_destroy(ArrayList list);

/**********************************************************
 * Adds a new element to the array list at the specified position. Shifts the other elements to make room.
 **********************************************************/
bool al_add(ArrayList list, size_t index, Element e);

/**********************************************************
 * Removes an element at the specified position. Shifts the other elements to fill the space.
 **********************************************************/
Element al_remove(ArrayList list, size_t index);

/**********************************************************
 * Replaces the element at the specified position with a new element.
 **********************************************************/
Element al_set(ArrayList list, size_t index, Element e);

/**********************************************************
 * Gets the element at the specified position.
 **********************************************************/
Element al_get(ArrayList list, size_t index);

/**********************************************************
 * Gets the index of an element.
 **********************************************************/
int al_index_of(ArrayList list, Element e);

/**********************************************************
 * Gets the number of elements in the list
 **********************************************************/
size_t al_size(ArrayList list);

/**********************************************************
 * Determines if the list is empty
 **********************************************************/
bool al_is_empty(ArrayList list);

/**********************************************************
 * Removes all elements from the list, setting the value to the NULL_ELEMENT defined above.
 **********************************************************/
void al_clear(ArrayList list);

/**********************************************************
 * Sorts the list using insertion sort.
 **********************************************************/
void al_sort(ArrayList list);

/**********************************************************
 * Prints the list to the console.
 **********************************************************/
void al_print(ArrayList list);

#endif