#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

#define NULL_ELEMENT 0;
#define Element int;

typedef struct linked_list_t *LinkedList;

/**********************************************************
 * Creates a new linked list.
 * Return: a linked_list_t pointer of type LinkedList
 **********************************************************/
LinkedList ll_create();

/**********************************************************
 * Destroys the given linked list.
 * Params: list - a linked_list_t pointer of type LinkedList
 * Return: void
 **********************************************************/
void ll_destroy(LinkedList list);

/**********************************************************
 * Adds a new element to the linked list at the specified
 * position. Shifts the other elements to make room.
 * Params: list - a linked_list_t pointer of type LinkedList
 *         index - the index at which to add the element
 *         e - element to be added to the list
 * Return: true if the element was added successfully and 
 *         false otherwise
 **********************************************************/
bool ll_add(LinkedList list, int index, Element e);

/**********************************************************
 * Removes an element at the specified position. Shifts
 * the other elements to fill the space.
 * Params: list - a linked_list_t pointer of type LinkedList
 *         index - the index at which to remove the element
 * Return: the removed element if removed successfully, or 
 *         the NULL_ELEMENT defined above if unable to
 *         remove
 **********************************************************/
Element ll_remove(LinkedList list, int index);

/**********************************************************
 * Replaces the element at the specified position with a 
 * new element.
 * Params: list - a linked_list_t pointer of type LinkedList
 *         index - the index at which to replace
 *         e - the new element to replace the original
 * Return: the previous value if set successfully, or the 
 *         NULL_ELEMENT defined above if unable to set
 **********************************************************/
Element ll_set(LinkedList list, int index, Element e);

/**********************************************************
 * Gets the element at the specified position.
 * Params: list - a linked_list_t pointer of type LinkedList
 *         index - the index at which to get the element
 * Return: the element at the specified position, or the 
 *         NULL_ELEMENT defined above if unable to get
 **********************************************************/
Element ll_get(LinkedList list, int index);

/**********************************************************
 * Gets the index of an element.
 * Params: list - a linked_list_t pointer of type LinkedList
 *         e - the element to search for
 * Return: the index of the element if found, or -1 if the 
 *         element is not found
 **********************************************************/
int ll_index_of(LinkedList list, Element e);

/**********************************************************
 * Gets the number of elements in the list
 * Params: list - a linked_list_t pointer of type LinkedList
 * Return: the number of elements in the list
 **********************************************************/
int ll_size(LinkedList list);

/**********************************************************
 * Determines if the list is empty
 * Params: list - a linked_list_t pointer of type LinkedList
 * Return: true if the list is empty and false otherwise
 **********************************************************/
bool ll_is_empty(LinkedList list);

/**********************************************************
 * Removes all elements from the list, setting the value
 * to the NULL_ELEMENT defined above.
 * Params: list - a linked_list_t pointer of type LinkedList
 **********************************************************/
void ll_clear(LinkedList list);

/**********************************************************
 * Prints the list to the console.
 * Params: list - a linked_list_t pointer of type LinkedList
 **********************************************************/
void ll_print(LinkedList list);

#endif