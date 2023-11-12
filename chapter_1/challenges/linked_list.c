#include <stdio.h>
#include <stdlib.h>

// Define doubly linked list nodenode
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

int main(int argc, char **argv)
{
    // User must input at least one word
    if (argc == 1)
    {
        printf("Usage: ./linked_list [SENTENCE]");
    }

    Node *sentence = create_node(argv[1]);
    if (sentence == NULL)
    {
        printf("Too much memory used, not enough available");
        return 1;
    }

    for (int i = 2; i < argc; i++)
    {
        // Condition on heap overflow
        if (add_front(&sentence, argv[i]))
        {
            _terminate(sentence);
            printf("Overused memory");
            return 1;
        }
    }

    print_linked(sentence);
    free_full(sentence);
}

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
