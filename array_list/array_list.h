/**
 * @file array_list.h
 * @brief Dynamic array list implementation using void pointers and function pointers.
 * 
 * This dynamic array uses void pointers as the data type to hold generic data.
 * It supports function pointers for sorting and comparison operations.
 */

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stddef.h>
#include <stdbool.h>

/** 
 * @brief Opaque pointer to the ArrayList structure.
 * 
 * The ArrayList is implemented as an opaque type, allowing clients to interact
 * with the structure without needing to know its internal representation.
 */
typedef struct array_list_t* ArrayList;

/** 
 * @brief Opaque pointer to an element stored in the ArrayList.
 */
typedef void* Element;

/**
 * @brief Comparison function pointer type for sorting.
 * 
 * @param a Pointer to the first element.
 * @param b Pointer to the second element.
 * @return 0 if a == b, negative value if a < b, positive value if a > b.
 */
typedef int (*CompareFunc)(const Element a, const Element b);

/**
 * @brief Creates a new dynamic array list with the specified initial capacity.
 * 
 * @param initial_capacity Initial capacity of the array list.
 * @return A new ArrayList instance, or NULL on failure.
 */
ArrayList al_create(size_t initial_capacity);

/**
 * @brief Destroys the ArrayList and frees all associated memory.
 * 
 * @param list The ArrayList to be destroyed.
 */
void al_destroy(ArrayList list);

/**
 * @brief Adds an element at the specified index in the ArrayList.
 * 
 * This function inserts an element into the ArrayList at the specified index, 
 * shifting elements if necessary.
 * 
 * @param list The ArrayList.
 * @param index The index at which to insert the element.
 * @param e The element to add.
 * @return true on success, false on failure (e.g., index out of bounds).
 */
bool al_add(ArrayList list, size_t index, Element e);

/**
 * @brief Removes the element at the specified index in the ArrayList.
 * 
 * This function removes the element at the given index and shifts the 
 * subsequent elements left.
 * 
 * @param list The ArrayList.
 * @param index The index of the element to remove.
 * @return The removed element, or NULL if index is out of bounds.
 */
Element al_remove(ArrayList list, size_t index);

/**
 * @brief Replaces the element at the specified index in the ArrayList.
 * 
 * This function sets the element at the specified index to the given element,
 * and returns the old element at that index.
 * 
 * @param list The ArrayList.
 * @param index The index of the element to replace.
 * @param e The new element to set.
 * @return The previous element at the index, or NULL if index is out of bounds.
 */
Element al_set(ArrayList list, size_t index, Element e);

/**
 * @brief Retrieves the element at the specified index in the ArrayList.
 * 
 * @param list The ArrayList.
 * @param index The index of the element to retrieve.
 * @return The element at the specified index, or NULL if index is out of bounds.
 */
Element al_get(ArrayList list, size_t index);

/**
 * @brief Finds the index of the first occurrence of an element in the ArrayList based on a comparison function.
 * 
 * This function searches the ArrayList for the specified element using a provided comparison function. 
 * The comparison function is used to determine if two elements are equal, rather than comparing memory addresses.
 * 
 * @param list The ArrayList.
 * @param e The element to search for.
 * @param compare A comparison function used to compare elements.
 * @return The index of the first occurrence of the element, or -1 if the element is not found.
 */
int al_index_of(ArrayList list, Element e, CompareFunc compare);


/**
 * @brief Returns the number of elements in the ArrayList.
 * 
 * @param list The ArrayList.
 * @return The number of elements in the ArrayList.
 */
size_t al_size(ArrayList list);

/**
 * @brief Checks if the ArrayList is empty.
 * 
 * @param list The ArrayList.
 * @return true if the ArrayList is empty, false otherwise.
 */
bool al_is_empty(ArrayList list);

/**
 * @brief Clears all elements from the ArrayList.
 * 
 * This function removes all elements from the ArrayList, but does not free the
 * ArrayList itself.
 * 
 * @param list The ArrayList.
 */
void al_clear(ArrayList list);

/**
 * @brief Sorts the ArrayList using the specified comparison function.
 * 
 * This function sorts the elements of the ArrayList in-place, based on the 
 * provided comparison function.
 * 
 * @param list The ArrayList.
 * @param compare The function used to compare elements.
 */
void al_sort(ArrayList list, CompareFunc compare);

#endif // ARRAY_LIST_H
