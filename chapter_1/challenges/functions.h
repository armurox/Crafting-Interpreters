#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>
// Define doubly linked list node
typedef struct Node
{
    struct Node *previous;
    char *word;
    struct Node *next;
} Node;

// Function declarations
Node *create_node(char *val);
int add_front(Node **start, char *val);
void _terminate(Node *start);
void print_linked(Node *start);
void print_reverse(Node *start);
#endif
