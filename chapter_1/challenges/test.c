#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void test_create_node()
{
    Node *head = create_node("Test");
    if (head == NULL)
    {
        printf("Heap Overflow\n");
    }
    assert(strcmp(head -> word, "Test") == 0);
    assert(head -> next == NULL);
    free(head);
    head = NULL;
}

void test_add_front()
{
    Node *head = create_node("Test");
    Node *temp = head;
    if (head == NULL)
    {
        printf("Heap Overflow\n");
    }

    add_front(&head, "Test_1");
    assert(strcmp(head -> word, "Test_1") == 0);
    assert(head -> next == temp);
    _terminate(head);
    head = NULL;
}

void test_delete_node()
{
    Node *head = create_node("Test");
    Node *temp = head;
    if (head == NULL)
    {
        printf("Heap Overflow\n");
    }

    add_front(&head, "Test_1");
    assert(strcmp(head -> word, "Test_1") == 0);
    assert(head -> next == temp);
    add_front(&head, "Test_2");
    add_front(&head, "Test_3");
    delete_node(&head, "Test_3");
    assert(strcmp(head -> word, "Test_2") == 0);
    assert(strcmp((head -> next) -> word, "Test_1") == 0);
    delete_node(&head, "Test_1");
    assert(strcmp(head -> word, "Test_2") == 0);
    assert(strcmp((head -> next) -> word, "Test") == 0);
    assert(head -> previous == NULL);
    assert((head -> next) -> next == NULL);
    _terminate(head);
    head = NULL;
}

int main()
{
    printf("Starting tests...\n");
    test_create_node();
    test_add_front();
    test_delete_node();
    printf("All tests passed!\n");
}
