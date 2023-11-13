# Homework 3
GCC = gcc
CONSERVATIVE_FLAGS = -std=c99 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

linked_list: linked_list.o functions.o
	$(GCC) -o linked_list linked_list.o functions.o

linked_list.o: linked_list.c functions.h
	$(GCC) -c linked_list.c $(CFLAGS)

# TODO: instructions to compile and run the test file
test: test.o functions.o
	$(GCC) -o test test.o functions.o
	# rm -f *.o
	# ./test
	# rm -f test

test.o: test.c functions.h
	$(GCC) -c test.c $(CFLAGS)

clean:
	rm -f *.o linked_list test

valtest:
	valgrind  --leak-check=full  --show-leak-kinds=all ./test
	rm -f *.o
	rm -rf test *.dSYM

val:
	valgrind  --leak-check=full  --show-leak-kinds=all ./linked_list
	rm -rf *.dSYM