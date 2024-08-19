#include <stdio.h>
#include "linked_list.h"

int main(void)
{
	printf("\n");

	printf("Creating list...\n");
	LinkedList list = ll_create();
	ll_print(list);
	printf("\n");

	

	printf("Adding 1-5 to list...\n");
	for (int i = 0; i < 5; i++) {
		ll_add(list, i, i+1);
	}
	ll_print(list);
	printf("\n");



	printf("Adding 6-20 to list...\n");
	for (int i = 5; i < 20; i++) {
		ll_add(list, i, i+1);
	}
	ll_print(list);
	printf("\n");

	printf("Removing from beginning of list...\n");
	ll_remove(list, 0);
	printf("Removing from middle of list...\n");
	ll_remove(list, ll_size(list)/2);
	printf("Removing from end of list...\n");
	ll_remove(list, ll_size(list)-1);
	ll_print(list);
	printf("\n");

	printf("Setting index 0 to 100...\n");
	ll_set(list, 0, 100);
	printf("Setting index 10 to -100\n");
	ll_set(list, 10, -100);
	ll_print(list);
	printf("\n");

	printf("Getting index 0..\n");
	printf("Index 0: %d\n", ll_get(list, 0));
	printf("Getting index 10..\n");
	printf("Index 10: %d\n", ll_get(list, 10));
	ll_print(list);
	printf("\n");

	printf("Getting index of value 100...\n");
	printf("Index: %d\n", ll_index_of(list, 100));
	printf("Getting index of value -100...\n");
	printf("Index: %d\n", ll_index_of(list, -100));
	printf("Getting index of value 1000...\n");
	printf("Index: %d\n", ll_index_of(list, 1000));
	ll_print(list);
	printf("\n");


	printf("Clearing list...\n");
	ll_clear(list);
	ll_print(list);
	printf("\n");

	printf("Destroying list...\n");
	ll_destroy(list);
	printf("\n");
}
