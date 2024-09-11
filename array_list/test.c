#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_list.h"

int compare_int(void *a, void *b)
{
	int *p1 = (int*)a;
	int *p2 = (int*)b;
	int n1 = *p1;
	int n2 = *p2;
	if (n1 == n2) return 0;
	return (n1 < n2) ? -1 : 1;
}

void print_int(void *n)
{
	int *num = (int*)n;
	printf("%d", *num);
}

Element create_int_element(int n) 
{
	void *e = malloc(sizeof(void*));
	return memcpy(e, &n, sizeof(int));
}

int main(void)
{
	printf("\n");

	printf("Creating list with initial capacity 5...\n");
	ArrayList list = al_create(5, compare_int, print_int);
	al_print(list);
	printf("\n");

	printf("Adding 1-5 to list...\n");
	for (int i = 0; i < 5; i++) {
		void *e = create_int_element(i+1);
		al_add(list, i, e);
	}
	al_print(list);
	printf("\n");

	printf("Adding 6-20 to list...\n");
	for (int i = 5; i < 20; i++) {
		void *e = create_int_element(i+1);
		al_add(list, i, e);
	}
	al_print(list);
	printf("\n");

	printf("Removing from beginning of list...\n");
	al_remove(list, 0);
	printf("Removing from middle of list...\n");
	al_remove(list, al_size(list)/2);
	printf("Removing from end of list...\n");
	al_remove(list, al_size(list)-1);
	al_print(list);
	printf("\n");

	printf("Setting index 0 to 100...\n");
	al_set(list, 0, create_int_element(100));
	printf("Setting index 10 to -100\n");
	al_set(list, 10, create_int_element(-100));
	al_print(list);
	printf("\n");

	printf("Getting index 0..\n");
	printf("Index 0:");
	print_int(al_get(list, 0));
	printf("\n");
	printf("Getting index 10..\n");
	printf("Index 10:");
	print_int(al_get(list, 10));
	printf("\n");
	al_print(list);
	printf("\n");

	printf("Getting index of value 100...\n");
	printf("Index: %d\n", al_index_of(list, create_int_element(100)));
	printf("Getting index of value -100...\n");
	printf("Index: %d\n", al_index_of(list, create_int_element(-100)));
	printf("Getting index of value 1000...\n");
	printf("Index: %d\n", al_index_of(list, create_int_element(1000)));
	al_print(list);
	printf("\n");


	printf("Clearing list...\n");
	al_clear(list);
	al_print(list);
	printf("\n");

	printf("Destroying list...\n");
	al_destroy(list);
	printf("\n");
}

