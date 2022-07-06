#ifndef STACK_H
#define STACK_H
#include "llist.h"
typedef struct _STACK
{
    LLIST stack;
} STACK;

STACK createStack();
int isEmptyStack(STACK S);
STACK push(STACK S, int k);
STACK pop(STACK S, int *k);
#endif
