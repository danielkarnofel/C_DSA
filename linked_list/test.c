#include <stdio.h>
#include "linked_list.h"

static void print(char *message) 
{
	printf("%s\n", message);
}

int main(void)
{
	printf("\n");

	print("Creating list...");
	ArrayList list = create();
	print_list(list);
	printf("\n");

	print("Adding 1-20 to list...");
	for (int i = 0; i < 20; i++) {
		add_to_list(list, i, i+1);
	}
	print_list(list);
	printf("\n");

	print("Removing from beginning of list...");
	remove_from_list(list, 0);
	print("Removing from middle of list...");
	remove_from_list(list, size(list)/2);
	print("Removing from end of list...");
	remove_from_list(list, size(list)-1);
	print_list(list);
	printf("\n");

	print("Setting index 0 to 100...");
	set(list, 0, 100);
	print("Setting index 10 to -100");
	set(list, 10, -100);
	print_list(list);
	printf("\n");

	print("Getting index 0..");
	printf("Index 0: %d\n", get(list, 0));
	print("Getting index 10..");
	printf("Index 10: %d\n", get(list, 10));
	print_list(list);
	printf("\n");

	print("Getting index of value 100...");
	printf("Index: %d\n", get_index(list, 100));
	print("Getting index of value -100...");
	printf("Index: %d\n", get_index(list, -100));
	print("Getting index of value 1000...");
	printf("Index: %d\n", get_index(list, 1000));
	print_list(list);
	printf("\n");


	print("Clearing list...");
	clear(list);
	print_list(list);
	printf("\n");

	print("Destroying list...");
	destroy(list);
	printf("\n");
}
