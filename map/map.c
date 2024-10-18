#include <stdbool.h>
#include <stdlib.h>
#include "map.h"

struct entry_node {
    Key key;
    Value val;
    struct entry_node *next;
};

struct map_t {
    struct entry_node **entries;
    size_t size;
    size_t capacity;
    HashFunc hash;
    CompareKey compare_key;
    CompareVal compare_val;
};

static struct entry_node *create_entry_node(Key key, Value val) {
    struct entry_node *new_entry = malloc(sizeof(struct entry_node));
    new_entry->key = key;
    new_entry->val = val;
    new_entry->next = NULL;
    return new_entry;
}

Map map_create(size_t capacity, HashFunc hash, CompareKey compare_key, CompareVal compare_val)
{
    Map map = malloc(sizeof(struct map_t));
    if (map == NULL) {
        return NULL;
    }

    map->entries = calloc(capacity, sizeof(struct entry_node *));
    if (map->entries == NULL) {
        free(map);
        return NULL;
    }

    map->size = 0;
    map->capacity = capacity;

    map->hash = hash;
    map->compare_key = compare_key;
    map->compare_val = compare_val;

    return map;
}

void map_destroy(Map map)
{
    for (size_t i = 0; i < map->capacity; i++) {
        if (map->entries[i] != NULL) {
            struct entry_node* curr = map->entries[i];
            while (curr != NULL) {
                struct entry_node* next = curr->next;
                free(curr);
                curr = next;
            }
        } else {
            free(map->entries[i]);
        }
    }
    free(map->entries);
    free(map);
}

bool map_put(Map map, const Key key, const Value val)
{
    int index = map->hash(key, map->capacity);

    // no entries at this index yet
    if (map->entries[index] == NULL) {
        map->entries[index] = create_entry_node(key, val);
        if (map->entries[index] == NULL) {
            return false; // failed to allocate new entry_node
        }
        map->size++;
        return true;
    }

    // hash collision
    struct entry_node *curr = map->entries[index];
    struct entry_node *prev = NULL;
    while (curr != NULL) {
        if (map->compare_key(key, curr->key) == 0) {
            return false; // there is already an entry for this key
        }
        prev = curr;
        curr = curr->next;
    }
    // add new node to end of linked list
    curr = create_entry_node(key, val);
    prev->next = curr;
    map->size++;
    return true;
}

Value map_remove(Map map, const Key key)
{
    int index = map->hash(key, map->capacity);

    // no entries found for this key
    if (map->entries[index] == NULL) {
        return NULL;
    }

    struct entry_node *curr = map->entries[index];

    // key is at first node
    if (map->compare_key(key, curr->key) == 0) {
        Value returnVal = curr->val;
        map->entries[index] = curr->next;
        free(curr);
        map->size--;
        return returnVal;
    }

    // key is not at first node
    struct entry_node *prev = curr;
    curr = curr->next;
    while (curr != NULL) {
        if (map->compare_key(key, curr->key) == 0) {
            Value returnVal = curr->val;
            prev->next = curr->next;
            free(curr);
            map->size--;
            return returnVal;
        }
        prev = curr;
        curr = curr->next;
    }

    // key not found in entry list
    return NULL;
}

Value map_set(Map map, const Key key, const Value val)
{
    int index = map->hash(key, map->capacity);

    struct entry_node *curr = map->entries[index];

    while (curr != NULL) {
        if (map->compare_key(key, curr->key) == 0) {
            Value returnVal = curr->val;
            curr->val = val;
            return returnVal;
        }
        curr = curr->next;
    }

    // key not found in entry list
    return NULL;
}

Value map_get(Map map, const Key key)
{
    int index = map->hash(key, map->capacity);

    struct entry_node *curr = map->entries[index];

    while (curr != NULL) {
        if (map->compare_key(key, curr->key) == 0) {
            return curr->val;
        }
        curr = curr->next;
    }

    // key not found in entry list
    return NULL;
}

bool map_contains(Map map, const Value val)
{
    for (size_t i = 0; i < map->capacity; i++) {
        struct entry_node *curr = map->entries[i];
        while (curr != NULL) {
            if (map->compare_val(val, curr->val) == 0) {
                return true;
            }
            curr = curr->next;
        }
    }
    return  false;
}

size_t map_size(Map map) {
    return map->size;
}













