#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

STACK createStack()
{
    STACK S;
    S.stack = createList();
    return S;
}

int isEmptyStack(STACK S)
{
    return (S.stack.head == NULL);
}

STACK push(STACK S, int k)
{
    S.stack = insertAtFront(S.stack, k);
    return S;
}

STACK pop(STACK S, int *k)
{
    if (isEmptyStack(S) == 0)
    {
        S.stack = deleteFromFront(S.stack, k);
    }
    return S;
}
