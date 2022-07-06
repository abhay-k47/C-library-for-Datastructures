#include "llist.h"
#include <stdio.h>
#include <stdlib.h>

// creates an empty linked list
LLIST createList()
{
    LLIST list;
    list.head = NULL;
    return list;
}

// search k in the list
int searchList(LLIST H, int k)
{
    NODE *node = H.head;

    // iterate till NULL is reached
    while (node != NULL)
    {
        if (node->value == k)
        {
            return 1;
        }
        node = node->next;
    }
    return 0;
}

// inserts a node at front of linked list
LLIST insertAtFront(LLIST H, int k)
{

    NODE *new = (NODE *)malloc(sizeof(NODE));
    new->value = k;
    new->next = H.head;
    H.head = new;
    return H;
}

// inserts a node at end of linked list
LLIST insertAtEnd(LLIST H, int k)
{
    NODE *new = (NODE *)malloc(sizeof(NODE));
    new->value = k;
    new->next = NULL;

    NODE *node = H.head;

    // if HEAD is NULL
    if (node == NULL)
    {
        H.head = new;
        return H;
    }

    while (node->next != NULL)
        node = node->next;
    node->next = new;
    return H;
}

// deletes a node from front of linked list
LLIST deleteFromFront(LLIST H, int *k)
{

    NODE *node = H.head;

    // if HEAD is NULL
    if (node == NULL)
    {
        return H;
    }

    *k = node->value;
    H.head = node->next;
    free(node);
    return H;
}

// deletes a node from end of linked list
LLIST deleteFromEnd(LLIST H, int *k)
{

    NODE *prev = NULL;
    NODE *curr = H.head;

    // if HEAD is NULL
    if (curr == NULL)
    {
        return H;
    }

    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }

    *k = curr->value;
    if (prev == NULL)
        H.head = NULL;
    else
        prev->next = NULL;

    free(curr);
    return H;
}

// deletes the first node having given value of linked list
LLIST deleteList(LLIST H, int k)
{
    NODE *curr = H.head;
    NODE *prev = NULL;

    while (curr != NULL && curr->value != k)
    {
        prev = curr;
        curr = curr->next;
    }

    // if HEAD is NULL
    if (curr == NULL)
        return H;

    if (prev == NULL)
        H.head = curr->next;
    else
        prev->next = curr->next;

    free(curr);
    return H;
}
