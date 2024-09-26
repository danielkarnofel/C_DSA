/**
 * @file singly_linked_list.h
 * @brief Singly linked list implementation using void pointers and function pointers.
 *
 * This linked list stores generic data and supports function pointers for comparison and sorting.
 */

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stddef.h>
#include <stdbool.h>

/** 
 * @brief Opaque pointer to the SinglyLinkedList structure.
 */
typedef struct singly_linked_list_t* SinglyLinkedList;

/** 
 * @brief Opaque pointer to an element stored in the SinglyLinkedList.
 */
typedef void* Element;

/**
 * @brief Comparison function pointer type for sorting and searching.
 *
 * @param a Pointer to the first element.
 * @param b Pointer to the second element.
 * @return 0 if a == b, negative value if a < b, positive value if a > b.
 */
typedef int (*CompareFunc)(const Element a, const Element b);

/**
 * @brief Creates a new singly linked list.
 *
 * @return A new SinglyLinkedList instance, or NULL on failure.
 */
SinglyLinkedList sll_create();

/**
 * @brief Destroys the SinglyLinkedList and frees all associated memory.
 *
 * @param list The SinglyLinkedList to be destroyed.
 */
void sll_destroy(SinglyLinkedList list);

/**
 * @brief Adds an element at the specified index in the SinglyLinkedList.
 * 
 * This function inserts an element into the list at the specified index,
 * shifting elements if necessary.
 * 
 * @param list The SinglyLinkedList.
 * @param index The index at which to insert the element.
 * @param e The element to add.
 * @return true on success, false on failure.
 */
bool sll_add(SinglyLinkedList list, size_t index, Element e);

/**
 * @brief Removes the element at the specified index in the SinglyLinkedList.
 *
 * @param list The SinglyLinkedList.
 * @param index The index of the element to remove.
 * @return The removed element, or NULL if index is out of bounds.
 */
Element sll_remove(SinglyLinkedList list, size_t index);

/**
 * @brief Replaces the element at the specified index in the SinglyLinkedList.
 *
 * @param list The SinglyLinkedList.
 * @param index The index of the element to replace.
 * @param e The new element to set.
 * @return The previous element at the index, or NULL if index is out of bounds.
 */
Element sll_set(SinglyLinkedList list, size_t index, Element e);

/**
 * @brief Retrieves the element at the specified index in the SinglyLinkedList.
 *
 * @param list The SinglyLinkedList.
 * @param index The index of the element to retrieve.
 * @return The element at the specified index, or NULL if index is out of bounds.
 */
Element sll_get(SinglyLinkedList list, size_t index);

/**
 * @brief Finds the index of the first occurrence of an element in the SinglyLinkedList using a comparison function.
 *
 * @param list The SinglyLinkedList.
 * @param e The element to search for.
 * @param compare The comparison function.
 * @return The index of the first occurrence, or -1 if not found.
 */
int sll_index_of(SinglyLinkedList list, Element e, CompareFunc compare);

/**
 * @brief Returns the number of elements in the SinglyLinkedList.
 *
 * @param list The SinglyLinkedList.
 * @return The number of elements in the list.
 */
size_t sll_size(SinglyLinkedList list);

/**
 * @brief Checks if the SinglyLinkedList is empty.
 *
 * @param list The SinglyLinkedList.
 * @return true if the list is empty, false otherwise.
 */
bool sll_is_empty(SinglyLinkedList list);

/**
 * @brief Clears all elements from the SinglyLinkedList.
 *
 * @param list The SinglyLinkedList.
 */
void sll_clear(SinglyLinkedList list);

/**
 * @brief Sorts the SinglyLinkedList using the specified comparison function.
 *
 * @param list The SinglyLinkedList.
 * @param compare The function used to compare elements.
 */
void sll_sort(SinglyLinkedList list, CompareFunc compare);

#endif // SINGLY_LINKED_LIST_H





