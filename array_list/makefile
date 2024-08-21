array_list: test.o array_list.o
		gcc -o array_list test.o array_list.o

test.o: test.c array_list.h
		gcc -c test.c

array_list.o: array_list.c array_list.h
		gcc -c array_list.c