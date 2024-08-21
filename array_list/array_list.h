#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdbool.h>

/* A dynamically expanding, array based implentation of an ordered list. */ 

#define Element int
#define NULL_ELEMENT 0

typedef struct array_list_t *ArrayList;

/**********************************************************
 * Creates a new array list.
 * Params: initial_capacity - initial storage capacity of 
 *         the array list; the list will be expanded if
 *         the capacity is exceeded
 * Return: an array_list_t pointer of type ArrayList
 **********************************************************/
ArrayList al_create(int initial_capacity);

/**********************************************************
 * Destroys the given array list.
 * Params: list - an array_list_t pointer of type ArrayList
 * Return: void
 **********************************************************/
void al_destroy(ArrayList list);

/**********************************************************
 * Adds a new element to the array list at the specified
 * position. Shifts the other elements to make room.
 * Params: list - an array_list_t pointer of type ArrayList
 *         index - the index at which to add the element
 *         e - element to be added to the list
 * Return: true if the element was added successfully and 
 *         false otherwise
 **********************************************************/
bool al_add(ArrayList list, int index, Element e);

/**********************************************************
 * Removes an element at the specified position. Shifts
 * the other elements to fill the space.
 * Params: list - an array_list_t pointer of type ArrayList
 *         index - the index at which to remove the element
 * Return: the removed element if removed successfully, or 
 *         the NULL_ELEMENT defined above if unable to
 *         remove
 **********************************************************/
Element al_remove(ArrayList list, int index);

/**********************************************************
 * Replaces the element at the specified position with a 
 * new element.
 * Params: list - an array_list_t pointer of type ArrayList
 *         index - the index at which to replace
 *         e - the new element to replace the original
 * Return: the previous value if set successfully, or the 
 *         NULL_ELEMENT defined above if unable to set
 **********************************************************/
Element al_set(ArrayList list, int index, Element e);

/**********************************************************
 * Gets the element at the specified position.
 * Params: list - an array_list_t pointer of type ArrayList
 *         index - the index at which to get the element
 * Return: the element at the specified position, or the 
 *         NULL_ELEMENT defined above if unable to get
 **********************************************************/
Element al_get(ArrayList list, int index);

/**********************************************************
 * Gets the index of an element.
 * Params: list - an array_list_t pointer of type ArrayList
 *         e - the element to search for
 * Return: the index of the element if found, or -1 if the 
 *         element is not found
 **********************************************************/
int al_index_of(ArrayList list, Element e);

/**********************************************************
 * Gets the number of elements in the list
 * Params: list - an array_list_t pointer of type ArrayList
 * Return: the number of elements in the list
 **********************************************************/
int al_size(ArrayList list);

/**********************************************************
 * Determines if the list is empty
 * Params: list - an array_list_t pointer of type ArrayList
 * Return: true if the list is empty and false otherwise
 **********************************************************/
bool al_is_empty(ArrayList list);

/**********************************************************
 * Removes all elements from the list, setting the value
 * to the NULL_ELEMENT defined above.
 * Params: list - an array_list_t pointer of type ArrayList
 **********************************************************/
void al_clear(ArrayList list);

/**********************************************************
 * Prints the list to the console.
 * Params: list - an array_list_t pointer of type ArrayList
 **********************************************************/
void al_print(ArrayList list);

#endif