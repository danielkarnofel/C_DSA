#include <stdio.h>
#include "array_list.h"

int main(void)
{
	printf("\n");

	printf("Creating list with initial capacity 5...\n");
	ArrayList list = al_create(5);
	al_print(list);
	printf("\n");

	printf("Adding 1-5 to list...\n");
	for (int i = 0; i < 5; i++) {
		al_add(list, i, i+1);
	}
	al_print(list);
	printf("\n");

	printf("Adding 6-20 to list...\n");
	for (int i = 5; i < 20; i++) {
		al_add(list, i, i+1);
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
	al_set(list, 0, 100);
	printf("Setting index 10 to -100\n");
	al_set(list, 10, -100);
	al_print(list);
	printf("\n");

	printf("Getting index 0..\n");
	printf("Index 0: %d\n", al_get(list, 0));
	printf("Getting index 10..\n");
	printf("Index 10: %d\n", al_get(list, 10));
	al_print(list);
	printf("\n");

	printf("Getting index of value 100...\n");
	printf("Index: %d\n", al_index_of(list, 100));
	printf("Getting index of value -100...\n");
	printf("Index: %d\n", al_index_of(list, -100));
	printf("Getting index of value 1000...\n");
	printf("Index: %d\n", al_index_of(list, 1000));
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

