#include <stdio.h>
#include <assert.h>
#include "array_list.h"

// Comparison function for integers
int int_compare(const Element a, const Element b) {
    return (*(int*)a - *(int*)b);
}

// Test ArrayList creation
void test_al_create() {
    ArrayList list = al_create(10);
    assert(list != NULL);
    assert(al_size(list) == 0);
    assert(al_is_empty(list) == true);
    al_destroy(list);
    printf("test_al_create passed.\n");
}

// Test adding elements to the ArrayList
void test_al_add() {
    ArrayList list = al_create(10);
    
    int a = 42, b = 99, c = 7;
    assert(al_add(list, 0, &a) == true); // Add to the start
    assert(al_add(list, 1, &b) == true); // Add to the end
    assert(al_add(list, 1, &c) == true); // Add to the middle
    
    assert(al_size(list) == 3);
    assert(*(int*)al_get(list, 0) == 42);
    assert(*(int*)al_get(list, 1) == 7);
    assert(*(int*)al_get(list, 2) == 99);
    
    al_destroy(list);
    printf("test_al_add passed.\n");
}

// Test removing elements from the ArrayList
void test_al_remove() {
    ArrayList list = al_create(10);
    
    int a = 42, b = 99, c = 7;
    al_add(list, 0, &a);
    al_add(list, 1, &b);
    al_add(list, 2, &c);

    // Remove the middle element
    Element removed = al_remove(list, 1);
    assert(*(int*)removed == 99);
    assert(al_size(list) == 2);

    // Remove the last element
    removed = al_remove(list, 1);
    assert(*(int*)removed == 7);
    assert(al_size(list) == 1);
    
    al_destroy(list);
    printf("test_al_remove passed.\n");
}

// Test setting elements in the ArrayList
void test_al_set() {
    ArrayList list = al_create(10);
    
    int a = 42, b = 99;
    al_add(list, 0, &a);
    
    // Set a new value at index 0
    Element old = al_set(list, 0, &b);
    assert(*(int*)old == 42);
    assert(*(int*)al_get(list, 0) == 99);
    
    al_destroy(list);
    printf("test_al_set passed.\n");
}

// Test finding an element in the ArrayList
void test_al_index_of() {
    ArrayList list = al_create(10);
    
    int a = 42, b = 99, c = 7;
    al_add(list, 0, &a);
    al_add(list, 1, &b);
    al_add(list, 2, &c);
    
    int target = 99;
    int index = al_index_of(list, &target, int_compare);
    assert(index == 1);
    
    target = 42;
    index = al_index_of(list, &target, int_compare);
    assert(index == 0);
    
    target = 999; // Non-existent element
    index = al_index_of(list, &target, int_compare);
    assert(index == -1);
    
    al_destroy(list);
    printf("test_al_index_of passed.\n");
}

// Test sorting the ArrayList
void test_al_sort() {
    ArrayList list = al_create(10);
    
    int a = 42, b = 99, c = 7;
    al_add(list, 0, &a);
    al_add(list, 1, &b);
    al_add(list, 2, &c);
    
    al_sort(list, int_compare);

    assert(*(int*)al_get(list, 0) == 7);
    assert(*(int*)al_get(list, 1) == 42);
    assert(*(int*)al_get(list, 2) == 99);
    
    al_destroy(list);
    printf("test_al_sort passed.\n");
}

// Main function to run all tests
int main() {
    test_al_create();
    test_al_add();
    test_al_remove();
    test_al_set();
    test_al_index_of();
    test_al_sort();

    printf("All tests passed successfully.\n");
    return 0;
}


