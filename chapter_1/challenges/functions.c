#include "functions.h"
#include <stdlib.h>

Node *create_node(char *val)
{
    Node *start = malloc(sizeof(Node));
    // Can't initialize value if start node cannot be allocated
    if (start == NULL)
    {
        return start;
    }

    start -> previous = NULL;
    start -> word = val;
    start -> next = NULL;
    return start;
}

int add_front(Node **start, char *val)
{
    Node *temp = create_node(val);
    // Return error code if memory overflow
    if (temp == NULL)
    {
        return 1;
    }

    // Add element to the front, appropriate adjusting all the node pointers
    temp -> next = *start;
    (*start) -> previous = temp;
    *start = temp;
    return 0;
}


void _terminate(Node *start)
{
    Node *prev = start;
    for (Node *curr = start -> next; curr != NULL; curr = curr -> next)
    {
        free(prev);
        prev = curr;
    }

    free(prev);
}

void print_linked(Node *start)
{
    for (Node *curr = start; curr != NULL; curr = curr -> next)
    {
        printf("%s ", curr -> word);
    }
    printf("\n");
}

void print_reverse(Node *start)
{
    Node *curr = start;
    while (curr -> next != NULL)
    {
        curr = curr -> next;
    }

    while (curr != NULL)
    {
        printf("%s ", curr -> word);
        curr = curr -> previous;
    }
    printf("\n");
}
