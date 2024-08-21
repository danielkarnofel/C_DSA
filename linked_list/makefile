linked_list: test.o linked_list.o
		gcc -o linked_list test.o linked_list.o

test.o: test.c linked_list.h
		gcc -c test.c

linked_list.o: linked_list.c linked_list.h
		gcc -c linked_list.c