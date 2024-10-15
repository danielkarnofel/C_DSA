/**
 * @file doubly_linked_list.h
 * @brief Doubly linked list implementation using void pointers and function pointers.
 *
 * This linked list stores generic data and supports function pointers for comparison and sorting.
 */

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stddef.h>
#include <stdbool.h>

/** 
 * @brief Opaque pointer to the DoublyLinkedList structure.
 */
typedef struct doubly_linked_list_t* DoublyLinkedList;

/** 
 * @brief Opaque pointer to an element stored in the DoublyLinkedList.
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
 * @brief Creates a new doubly linked list.
 *
 * @return A new DoublyLinkedList instance, or NULL on failure.
 */
DoublyLinkedList dll_create(size_t initial_capacity);

/**
 * @brief Destroys the DoublyLinkedList and frees all associated memory.
 *
 * @param list The DoublyLinkedList to be destroyed.
 */
void dll_destroy(DoublyLinkedList list);

/**
 * @brief Adds an element at the specified index in the DoublyLinkedList.
 *
 * @param list The DoublyLinkedList.
 * @param index The index at which to insert the element.
 * @param e The element to add.
 * @return true on success, false on failure.
 */
bool dll_add(DoublyLinkedList list, size_t index, Element e);

/**
 * @brief Removes the element at the specified index in the DoublyLinkedList.
 *
 * @param list The DoublyLinkedList.
 * @param index The index of the element to remove.
 * @return The removed element, or NULL if index is out of bounds.
 */
Element dll_remove(DoublyLinkedList list, size_t index);

/**
 * @brief Replaces the element at the specified index in the DoublyLinkedList.
 *
 * @param list The DoublyLinkedList.
 * @param index The index of the element to replace.
 * @param e The new element to set.
 * @return The previous element at the index, or NULL if index is out of bounds.
 */
Element dll_set(DoublyLinkedList list, size_t index, Element e);

/**
 * @brief Retrieves the element at the specified index in the DoublyLinkedList.
 *
 * @param list The DoublyLinkedList.
 * @param index The index of the element to retrieve.
 * @return The element at the specified index, or NULL if index is out of bounds.
 */
Element dll_get(DoublyLinkedList list, size_t index);

/**
 * @brief Finds the index of the first occurrence of an element in the DoublyLinkedList using a comparison function.
 *
 * @param list The DoublyLinkedList.
 * @param e The element to search for.
 * @param compare The comparison function.
 * @return The index of the first occurrence, or -1 if not found.
 */
int dll_index_of(DoublyLinkedList list, Element e, CompareFunc compare);

/**
 * @brief Returns the number of elements in the DoublyLinkedList.
 *
 * @param list The DoublyLinkedList.
 * @return The number of elements in the list.
 */
size_t dll_size(DoublyLinkedList list);

/**
 * @brief Checks if the DoublyLinkedList is empty.
 *
 * @param list The DoublyLinkedList.
 * @return true if the list is empty, false otherwise.
 */
bool dll_is_empty(DoublyLinkedList list);

/**
 * @brief Clears all elements from the DoublyLinkedList.
 *
 * @param list The DoublyLinkedList.
 */
void dll_clear(DoublyLinkedList list);

/**
 * @brief Sorts the DoublyLinkedList using the specified comparison function.
 *
 * @param list The DoublyLinkedList.
 * @param compare The function used to compare elements.
 */
void dll_sort(DoublyLinkedList list, CompareFunc compare);

#endif // DOUBLY_LINKED_LIST_H






