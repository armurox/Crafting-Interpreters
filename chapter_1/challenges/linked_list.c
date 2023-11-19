#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

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

    // Just removing any mention of Bob from sentence
    delete_node(&sentence, "Bob");

    print_reverse(sentence);
    _terminate(sentence);
}
