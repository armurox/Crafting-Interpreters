#include "functions.h"
#include <stdlib.h>
#include <string.h>

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

// Add nodes to front (stack implementation)
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

// Print out sentence in order it is put in (needs to be reversed as add node is a stack)
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


void delete_node(Node **start, char *val)
{
    for (Node *curr = *start; curr != NULL; curr = curr -> next)
    {
        // Delete middle nodes
        if (strcmp(curr -> word, val) == 0 && curr != *start && curr -> next != NULL)
        {
            (curr -> previous) -> next = curr -> next;
            (curr -> next) -> previous = curr -> previous;
            free(curr);
            break;
        }

        // Delete first node
        else if (strcmp(curr -> word, val) == 0 && curr == *start)
        {
            *start = curr -> next;
            (*start) -> previous = NULL;
            free(curr);
            break;
        }

        // Delete end node
        else if (strcmp(curr -> word, val) == 0)
        {
            (curr -> previous) -> next = NULL;
            free(curr);
            break;
        }
    }
}
