#ifndef QUEUE_H
#define QUEUE_H
#include "llist.h"
typedef struct _QUEUE
{
    LLIST queue;
} QUEUE;
QUEUE createQueue();
int isEmptyQueue(QUEUE Q);
QUEUE enqueue(QUEUE Q, int k);
QUEUE dequeue(QUEUE Q, int *k);
#endif