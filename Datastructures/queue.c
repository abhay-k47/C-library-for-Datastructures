#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

QUEUE createQueue()
{
    QUEUE Q;
    Q.queue = createList();
    return Q;
}

int isEmptyQueue(QUEUE Q)
{
    return (Q.queue.head == NULL);
}

QUEUE enqueue(QUEUE Q, int k)
{
    Q.queue = insertAtEnd(Q.queue, k);
    return Q;
}

QUEUE dequeue(QUEUE Q, int *k)
{
    if (isEmptyQueue(Q) == 0)
        Q.queue = deleteFromFront(Q.queue, k);
    return Q;
}
