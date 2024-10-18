#ifndef MAP_H
#define MAP_H

#include <stdbool.h>

/**
 * @brief Opaque pointer to the Map structure.
 * 
 * The Map is implemented as an opaque type, allowing clients to interact
 * with the structure without needing to know its internal representation.
 */
typedef struct map_t* Map;

/**
 * @brief A generic value type used for storing data in the map.
 */
typedef void* Value;

/**
 * @brief A generic key type used for identifying values in the map.
 */
typedef void* Key;

/**
 * @brief A function pointer type used for hashing.
 *
 * @param a The key to be hashed.
 * @param b The capacity of the array used in the map.
 * @return An integer representing the index of the value-key pair in the map array. 
 */
typedef int (*HashFunc)(const Key key, const size_t capacity);

/**
 * @brief A function pointer type used for comparing two keys.
 *
 * @param a The first key to compare.
 * @param b The second key to compare.
 * @return An integer less than, equal to, or greater than zero if a is found, respectively,
 *         to be less than, equal to, or greater than b.
 */
typedef int (*CompareKey)(const Key a, const Key b);

/**
 * @brief A function pointer type used for comparing two values.
 *
 * @param a The first value to compare.
 * @param b The second value to compare.
 * @return An integer less than, equal to, or greater than zero if a is found, respectively,
 *         to be less than, equal to, or greater than b.
 */
typedef int (*CompareVal)(const Value a, const Value b);

/**
 * @brief Creates a new map with the given initial capacity.
 *
 * @param capacity The initial capacity of the map.
 * @return A handle to the newly created map, or NULL if memory allocation fails.
 */
Map map_create(size_t capacity, HashFunc hash, CompareKey compare_key, CompareVal compare_val);

/**
 * @brief Destroys the map and frees all associated memory.
 *
 * @param map A handle to the map to be destroyed.
 */
void map_destroy(Map map);

/**
 * @brief Inserts a new key-value pair into the map.
 *
 * If the key already exists, returns false and does not update the value.
 *
 * @param map A handle to the map.
 * @param key A pointer to the key.
 * @param value A pointer to the value to be stored.
 * @return true if the key-value pair was successfully inserted, false otherwise.
 */
bool map_put(Map map, Key key, Value val);

/**
 * @brief Removes a key-value pair from the map.
 *
 * @param map A handle to the map.
 * @param key A pointer to the key of the pair to be removed.
 * @return A pointer to the value associated with the removed key, or NULL if the key was not found.
 */
Value map_remove(Map map, Key key);

/**
 * @brief Updates the value for an existing key in the map.
 *
 * @param map A handle to the map.
 * @param key A pointer to the key whose value is to be updated.
 * @param value A pointer to the new value.
 * @return The previous value if set successfully, NULL otherwise
 */
Value map_set(Map map, Key key, Value val);

/**
 * @brief Retrieves the value associated with a given key.
 *
 * @param map A handle to the map.
 * @param key A pointer to the key.
 * @return A pointer to the value associated with the key, or NULL if the key was not found.
 */
Value map_get(Map map, Key key);

/**
 * @brief Checks if a given value exists in the map.
 *
 * @param map A handle to the map.
 * @param value A pointer to the value to search for.
 * @return true if the value exists in the map, false otherwise.
 */
bool map_contains(Map map, Value val);

/**
 * @brief Returns the number of entries in the map
 *
 * @param map A handle to the map.
 * @return A size_t representing the number of entries. 
 */
size_t map_size(Map map);

#endif // MAP_H
